#include <string>
#include <cstdio>
#include <climits>

using namespace std;

const int MAXN = 50007;

int n, m;

struct Node {
    int l, r, mid, len;  

    // max consecutive length
    // max consecutive empty length from l boundary
    // max consecutive empty length from r boundary
    int lempty, lhead, ltail;

    // tag type: 1 checkin, -1 checkout, 0 none
    // time of the tag
    int tag, time;
};

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1 | 1; }

Node t[MAXN<<2];

void refresh(int x) {
    int ll = ls(x), rr = rs(x);
    t[x].lempty = max(max(t[ll].lempty, t[rr].lempty), 
                      t[ll].ltail+t[rr].lhead);
    t[x].lhead = t[ll].lhead + (t[ll].lempty==t[ll].len ? t[rr].lhead : 0);
    t[x].ltail = t[rr].ltail + (t[rr].lempty==t[rr].len ? t[ll].ltail : 0);
}

void build(int node, int l, int r) {
    Node& n = t[node];
    n.l = l;
    n.r = r;
    n.mid = (l+r) >> 1;
    n.len = r - l + 1;
    n.tag = 0;
    n.time = INT_MAX;
    n.lempty = n.lhead = n.ltail = n.len;

    if (l!=r) {
        build(ls(node), l, n.mid);
        build(rs(node), n.mid+1, r);
    }
}

void apply(int x, int type, int tm) {
    Node& n = t[x];
    if (tm>n.time) return;
    n.time = tm;
    n.tag = type;
    if (type==1) // check in
        n.lempty = n.lhead = n.ltail = 0;
    else 
        n.lempty = n.lhead = n.ltail = n.len;
}

void push_down(int x) {
    if (t[x].tag!=0) {
        apply(ls(x), t[x].tag, t[x].time);
        apply(rs(x), t[x].tag, t[x].time);
        t[x].tag = 0;
        t[x].time = INT_MAX;
    }
}

int query(int node, int ql) {
    Node &n = t[node], &nl = t[ls(node)], &nr = t[rs(node)];
    
    if (n.lempty<ql || n.tag==1) return -1;
    if (n.tag==-1) return n.l;
    
    // if tag!=0, we can directly return a value
    // until here, we know tag==0, so no need to push_down(node);
    // push_down(node);

    if (nl.lempty>=ql) return query(ls(node), ql);
    if (nl.ltail+nr.lhead>=ql) return nl.r - nl.ltail + 1;
    if (nr.lempty>=ql) return query(rs(node), ql);

    return -1;
}

void update(int node, int l, int r, int type) {
    Node &n = t[node];
    // out of boundary
    if (n.r<l || n.l>r) return;
    // all in [l,r]
    if (l<=n.l && n.r<=r) 
        apply(node, type, m);
    else {
        push_down(node);
        update(ls(node), l, r, type);
        update(rs(node), l, r, type);
        refresh(node);
    }
}

int main() {
    scanf("%d %d", &n, &m);

    build(1, 1, n);

    int op, x, d;
    while (m--) {
        scanf("%d", &op);
        if (op==1) {
            scanf("%d", &d);
            int start = query(1, d);
            if (start==-1) 
                printf("0\n");
            else {
                printf("%d\n", start);
                update(1, start, start+d-1, 1);
            }
        } else {
            scanf("%d %d", &x, &d);
            update(1, x, x+d-1, -1);
        }
    }

    return 0;
}