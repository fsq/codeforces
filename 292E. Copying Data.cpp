#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// zkw segment tree

int n, m, h;
vector<int> t;   // actual elem value, only last n useful
vector<int> len; // length of each segment
vector<int> d;   // tag, start index of the copied segment
vector<int> tm;  // time_stamp of the last copy
vector<int> a;   

inline int ls(int i) { return i<<1; }
inline int rs(int i) { return i<<1 | 1; }

int geth(int n) {
    for (int i=sizeof(int)*8-1; i>=0; --i)
        if (n>>i & 1) 
            return i;
    return sizeof(int)*8;
}

void build() {
    t = len = vector<int>(n<<1 | 1, 0);
    d = vector<int>(n<<1 | 1, -1);
    tm = vector<int>(n<<1 | 1, INT_MAX);
    h = geth(n);
    for (int j,i=0; i<n; ++i) {
        scanf("%d", &j);
        a.push_back(j);
    }
    for (int i=0; i<n; ++i) {
        scanf("%d", &t[n+i]);
        len[n+i] = 1;
    }
    for (int i=n-1; i>0; --i)
        len[i] = len[ls(i)] + len[rs(i)];
}

// apply tag to node i, starting index ind, time_stamp _tm
void apply(int i, int ind, int _tm) {
    // if i has a newer copy, disgard curnt one
    if (_tm > tm[i]) return;
    tm[i] = _tm;
    if (i < n) 
        d[i] = ind;
    else 
        t[i] = a[ind];   // if i is leaf, change value
}

void update(int l, int r, int ind) {
    int x = ind, y = ind + r - l;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l&1) {
            apply(l, x, m); 
            x += len[l++];
        }
        if (r&1) {
            --r;
            apply(r, y-=len[r], m);
        }
    }
}

int query(int p) {
    int p0 = p;
    p += n;
    // push tags downwards from root to p
    for (int s=h; s>0; --s) {
        int i = p >> s;
        if (d[i]!=-1) {
            apply(ls(i), d[i], tm[i]);
            apply(rs(i), d[i]+len[ls(i)], tm[i]); // d[i]+len[ls]
            d[i] = -1;
            tm[i] = INT_MAX;
        }
    }
    return t[n+p0];
}

int main() {
    scanf("%d %d", &n, &m);

    build();

    for (int t,x,y,k; m; --m) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d %d", &x, &y, &k);
            update(y-1, y-1+k, x-1);
        } else {
            scanf("%d", &x);
            printf("%d\n", query(x-1));
        }
    }

    return 0;
}