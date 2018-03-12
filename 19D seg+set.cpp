#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#define cind(x) scanf("%d", &x)
#define cindln(x) scanf("%d\n", &x)
#define cinc(x) scanf("%c", &x)
#define emptyy(n) n.st.empty()
#define stmaxy(st) st.empty() ? -1 : *prev(st.end(), 1)

const int MAXN = 200007;

using namespace std;

class Node {
public:
    int maxy;
    int l, r;
    int s[2];
    Node() {}
};

Node t[MAXN<<2];
int op[MAXN][3]; 
vector<int> pos;
vector<int> a;
vector<multiset<int>> st;

inline int get_mid(int l, int r) { return (l+r) >> 1; }

inline void refresh(int n) { 
    t[n].maxy = max(t[t[n].s[0]].maxy, t[t[n].s[1]].maxy); 
}

void build(int node, int l, int r) {
    Node& n = t[node];
    n.l = l, n.r = r;
    n.maxy = -1;
    if (l==r) 
        n.s[0] = n.s[1] = 0;
    else {
        int mid = get_mid(l, r);
        build(n.s[0] = node<<1,   l,   mid);
        build(n.s[1] = node<<1|1, mid+1, r);
    }
}

void update(int node, int pos, int y, int o) {
    Node& n = t[node];
    if (n.l==n.r) {
        if (o==1) 
            st[pos].insert(y);
        else 
            st[pos].erase(st[pos].find(y));
        n.maxy = stmaxy(st[pos]);
    } else {
        update(n.s[pos>get_mid(n.l, n.r)], pos, y, o);
        refresh(node);
    }
}

int query(int node, int l, int y) {
    Node& n = t[node];
    if (n.r<l || n.maxy<=y) return -1;

    if (n.l==n.r) return n.l;

    if (l<=get_mid(n.l, n.r)) {
        int res = query(n.s[0], l, y);
        if (res!=-1) return res;
    } 

    return query(n.s[1], l, y);
}

int main() {
    int nop;
    cindln(nop);

    char cop, tc;
    for (int i=0; i<nop; ++i) {
        cinc(cop);
        for (tc='1'; tc!=' '; cinc(tc));
        if (cop=='a') op[i][0] = 0;
        else if (cop=='r') op[i][0] = 1;
                    else   op[i][0] = 2;

        cind(op[i][1]), cindln(op[i][2]);
        if (cop=='a')
            a.push_back(op[i][1]);
    }

    // discretization
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    st.resize(a.size()+1);

    // if a.size==0, runtime error
    if (!a.empty()) build(1, 1, a.size());

    for (int o,x,y,pos,i=0; i<nop; ++i) {
        o = op[i][0], x = op[i][1], y = op[i][2];
        pos = lower_bound(a.begin(), a.end(), x + (o==2)) 
                - a.begin() + 1;

        if (o<=1) {
            update(1, pos, y, 1^o);
        } else {
            int p = query(1, pos, y);
            if (p==-1)
                printf("-1\n");
            else 
                printf("%d %d\n", a[p-1], 
                            *st[p].upper_bound(y));
        }
    }
    

    return 0;
}