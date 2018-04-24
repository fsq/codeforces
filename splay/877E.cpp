#include <cstdio>
#include <vector>
#include <algorithm>
#define cind(x) scanf("%d", &x)
#define cinc(x) scanf("%c", &x)
#define RANGE(i,a,b) for (int i=(a); i<=b; ++i)

using namespace std;

const int MAXN =  2e5 + 7;

class Tnode {
public:
    int id;
    int rt;
    Tnode() {}
};

class Node {
public:
    int s[2];
    int cnt,l,r;
    int d;
    Node() { d=s[0]=s[1] = 0; }
};

vector<int> sons[MAXN];
Tnode ot[MAXN];
Node t[MAXN<<2];
int initon[MAXN];
int n;

inline int get_mid(int l, int r) { return (l+r)>>1; }
inline void refresh(int x) { t[x].cnt = t[t[x].s[0]].cnt + t[t[x].s[1]].cnt; }

int dfs(int now, int id) {
    ot[now].id = id;
    for (auto nxt : sons[now]) 
        id = dfs(nxt, id+1);
    ot[now].rt = id;
    return id;
}

void build(int node, int l, int r) {
    Node& n = t[node];
    n.l = l, n.r = r;
    if (l==r) 
        n.cnt = initon[l];
    else {
        int mid = get_mid(l, r);
        build(n.s[0]=node<<1, l, mid);
        build(n.s[1]=node<<1|1, mid+1, r);
        refresh(node);
    }
}

void apply(int x, int v) {
    if (v==1) {
        t[x].d ^= 1;
        t[x].cnt = t[x].r-t[x].l+1 - t[x].cnt;
    }
}

void push(int x) {
    apply(t[x].s[0], t[x].d);
    apply(t[x].s[1], t[x].d);
    t[x].d = 0;
}

int query(int node, int l, int r) {
    Node& n = t[node];
    if (l<=n.l && n.r<=r) return n.cnt;
    if (n.r<l || n.l>r) return 0;
    push(node);
    int mid = get_mid(n.l, n.r);
    if (r<=mid)
        return query(n.s[0], l, r);
    else
        return query(n.s[0], l, r) + query(n.s[1], l, r);
}

void update(int node, int l, int r) {
    Node& n = t[node];
    if (n.r<l || n.l>r) return;
    if (l<=n.l && n.r<=r) 
        apply(node, 1);
    else {
        push(node);
        update(n.s[0], l, r);
        update(n.s[1], l, r);
        refresh(node);
    }
}


int main() {
    cind(n);
    RANGE(i, 2, n) {
        int j;
        cind(j);
        sons[j].push_back(i);
    }

    dfs(1, 1);

    RANGE(i, 1, n)  cind(initon[ot[i].id]);

    build(1, 1, n);

    int q,x;
    cind(q);

    char op;
    cinc(op);    
    while (q--) {
        cinc(op), cinc(op), cinc(op);
        cind(x);    
        if (op=='t') 
            printf("%d\n", query(1, ot[x].id, ot[x].rt));
        else 
            update(1, ot[x].id, ot[x].rt);
        cinc(op);
    }
    return 0;
}