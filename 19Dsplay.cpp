#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#define cind(x) scanf("%d", &x)
#define cinc(x) scanf("%c", &x)
#define cindln(x) scanf("%d\n", &x)
#define stmax(st) *prev(st.end(), 1)

using namespace std;

class Node {
public:
    int s[2], f;
    int maxy;
    int x;
    multiset<int> st;
    Node() { 
        s[0] = s[1] = 0;
        f = 0;
        maxy = -1;
    }
    Node(int nx, int ny):Node() {
        x = nx;
        st.insert(ny);
        maxy = ny;
    }
};

Node t[300007];
int nt = 0;
int root = 0;

inline void setroot(int x) { root = x, t[x].f = 0; }

void refresh(int p) {
    t[p].maxy = stmax(t[p].st);
        for (int i=0; i<2; ++i)
            if (t[p].s[i])
                t[p].maxy = max(t[p].maxy, t[t[p].s[i]].maxy);
}

void link(int x, int p, bool right) {
    if (p) {
        t[p].s[right] = x;
        refresh(p);
    }
    if (x)
        t[x].f = p;
}

void rotate(int y, bool right) {
    int x = t[y].s[!right], p = t[y].f;
    link(x, p, y==t[p].s[1]);
    link(t[x].s[right], y, !right);
    link(y, x, right);
}

void splay(int x) {
    while (t[x].f) {
        int p = t[x].f;
        bool lx = t[p].s[0] == x;
        if (p==root)
            rotate(p, lx);
        else {
            int pp = t[p].f;
            bool lp = t[pp].s[0] == p;
            if (lx ^ lp)
                rotate(p, lx), rotate(pp, lp);
            else
                rotate(pp, lp), rotate(p, lx);
        }
    }
    root = x;
}

void insert(int x, int y) {
    int n = root, p = 0;
    while (n) 
        if (t[n].x==x) {
            t[n].st.insert(y);
            t[n].maxy = max(t[n].maxy, stmax(t[n].st));
            splay(n);
            return;
        } else {
            p = n;
            n = t[n].s[x>t[n].x];
        }
    t[n=(++nt)] = Node(x, y);
    link(n, p, x>t[p].x);
    splay(n);
}

int find(int x) {
    int now = root;
    while (now && t[now].x != x)
        now = t[now].s[x>t[now].x];
    return now;
}

int find_min(int x) {
    while (t[x].s[0]) x = t[x].s[0];
    return x;
}

void remove(int x, int y) {
    int n = find(x);
    splay(n);
    t[n].st.erase(t[n].st.find(y));

    if (!t[n].st.empty()) {
        refresh(n);    
        return;
    }
    int ls = t[n].s[0], rs = t[n].s[1];

    if (!(ls && rs))
        setroot(ls ? ls : (rs ? rs : 0));
    else {
        int suc = find_min(rs);
        if (suc==rs) {
            link(ls, suc, false);
            setroot(suc);
        } else {
            int psuc = t[suc].f;
            link(t[suc].s[1], psuc, false);
            link(ls, suc, false);
            link(rs, suc, true);
            setroot(suc);
            splay(suc);
        }
    }
}

int find(int node, int x, int y) {
    Node& n = t[node];

    if (!node || n.maxy<=y) return 0;
    int res = n.x>x ? find(n.s[0], x, y) : 0;
    if (res) return res;
    if (n.x>x && stmax(n.st)>y) return node;
    return find(n.s[1], x, y);
}

int main() {
    int nop;
    cindln(nop);

    char c;
    int x, y;
    while (nop--) {
        cinc(c);
        for (char tc='a'; tc!=' '; cinc(tc));
        cind(x), cindln(y);

        if (c=='a') {
            insert(x, y);
        } else if (c=='r') {
            remove(x, y);
        } else {
            int node = find(root, x, y);
            if (!node)
                printf("%d\n", -1);
            else {
                splay(node);
                int ansy = *t[node].st.upper_bound(y);
                printf("%d %d\n", t[node].x, ansy);
            }
        }
    }

    return 0;
}   