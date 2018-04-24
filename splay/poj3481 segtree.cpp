#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
#define cind(x) scanf("%d", &x)
using namespace std;

const int NONE = 0;
const int MAXN = 100007;

class Node {
public:
    int id[2]; // min max
    int s[2]; // ls rs
    int l, r;
    int k;
    Node() { }

} t[MAXN<<2];

int n;

vector<int> a;
int q[MAXN*10][3];

inline int get_mid(int l, int r) { return (l+r)>>1; }

void refresh(int x) {
    for (int i=0; i<2; ++i)
        t[x].id[i] = t[t[x].s[i]].id[i]==NONE ? 
                    t[t[x].s[i^1]].id[i] : t[t[x].s[i]].id[i];
}

void build(int node, int l, int r) {
    Node& n = t[node];
    n.k = n.id[0] = n.id[1] = NONE;
    n.l = l, n.r = r;
    if (l!=r) {
        n.s[0] = node<<1, n.s[1] = node<<1 | 1;
        int mid = get_mid(l, r);
        build(n.s[0], l, mid);
        build(n.s[1], mid+1, r);
    }
}

void insert(int node, int pos, int k) {
    Node& n = t[node];
    if (n.l==n.r) {
        n.id[0] = n.id[1] = pos;
        n.k = k;
    } else {
        insert(n.s[pos>get_mid(n.l, n.r)], pos, k);
        refresh(node);
    }
}

int query(int node, int flag) {
    Node& n = t[node];

    if (n.id[0]==NONE) return NONE;

    int ret;
    if (n.l==n.r) {
        ret = n.k;
        n.k = n.id[0] = n.id[1] = NONE;
    } else {
        if (t[n.s[flag]].id[flag] != NONE) 
            ret = query(n.s[flag], flag);
        else 
            ret = query(n.s[!flag], flag);
        refresh(node);
    }
    return ret;
}


int main() {
    int x,y,qn = 0;
    while (true) {
        cind(q[qn][0]);
        if (q[qn][0]==0) break;
        if (q[qn][0]==1) {
            cind(q[qn][1]), cind(q[qn][2]);
            a.push_back(q[qn][2]);
        }
        ++qn;
    }
        
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (!a.empty()) build(1, 1, a.size());

    for (int i=0; i<qn; ++i) {
        if (q[i][0]==1) {
            int k = q[i][1], prio = q[i][2];
            int pos = lower_bound(a.begin(), a.end(), prio) - a.begin() + 1;
            insert(1, pos, k);
        } else {
            int id = query(1, 1 ^ (q[i][0]-2));
            printf("%d\n", id==NONE ? 0 : id);
        }
    }

    return 0;
}