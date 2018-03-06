#include <cstdio>
#include <algorithm>
#include <vector>

#define cind(x) scanf("%d", &x)

using namespace std;

class Node {
public:
    int ind, val;
    int s[2];
    int f;
    Node() {}
    Node(int id, int v, int fa):ind(id),val(v),f(fa) {
        s[0] = s[1] = 0;
    }
};

int root = 0;
vector<Node> t(1);

void push(int x) {
    for (int i=0; i<2; ++i)
        if (t[x].s[i]) t[t[x].s[i]].f = x;
}

void rotate(int y, bool right) {
    int x = t[y].s[!right], p = t[y].f;
    t[p].s[y==t[p].s[1]] = x;
    t[x].f = p;
    t[y].s[!right] = t[x].s[right];
    t[x].s[right] = y;
    push(x), push(y);
}

void splay(int x) {
    while (t[x].f) {
        int p = t[x].f;
        bool lx = x==t[p].s[0];
        if (p==root) 
            rotate(p, lx); 
        else {
            int pp = t[p].f;
            bool lp = p==t[pp].s[0];
            if (lx ^ lp)
                rotate(p, lx), rotate(pp, lp);
            else 
                rotate(pp, lp), rotate(p, lp);
        }
    }
    root = x;
}

void insert(int val, int ind) {
    int now = root, pp = 0;
    while (now) {
        pp = now;
        now = t[now].s[val>t[now].val];
    }
    now = t.size();
    t.push_back(Node(ind, val, pp));
    if (pp) t[pp].s[val>t[pp].val] = now;
    splay(now);
}

int find(bool max, int p=root) {
    if (p) while (t[p].s[max]) p = t[p].s[max];
    return p;
}

int remove(int p) {
    if (p==0) return 0;
    int ret = t[p].ind;

    splay(p);

    if (!t[p].s[0] && !t[p].s[1]) 
        root = 0;
    else if (!t[p].s[1]) {
        root = t[p].s[0];
        t[root].f = 0;
    } else {
        int suc = find(false, t[p].s[1]);
        t[p].val = t[suc].val;
        t[p].ind = t[suc].ind;
        int psuc = t[suc].f;
        t[psuc].s[suc==t[psuc].s[1]] = t[suc].s[1];
        push(psuc);
        splay(psuc);
    }

    return ret;
}

int main() {
    
    int x;
    while (true) {
        cind(x);
        if (x==0) break;
        if (x==1) {
            int weight, index;
            cind(index), cind(weight);

            insert(weight, index);

        } else if (x==2) {
            int p = find(true);
            int res = remove(p);
            printf("%d\n", res);
        } else {
            int p = find(false);
            int res = remove(p);
            printf("%d\n", res);
        }
    }

    return 0;
}