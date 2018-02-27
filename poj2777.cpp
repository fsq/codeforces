#include <cstdio>
#include <memory>
#include <climits>

using namespace std;

const int MAXN = 1e5 + 7;

int n, t, h, op;
int tr[MAXN<<1 | 1];
int tag[MAXN<<1 | 1];
int tm[MAXN<<1 | 1];

inline int ls(int i) { return i<<1; }
inline int rs(int i) { return i<<1 | 1; }
inline void refresh(int i) { tr[i] = tr[ls(i)] | tr[rs(i)]; }

int get_h(int n) {
    for (int i=sizeof(int)*8-1; i>=0; --i)
        if (n>>i & 1) 
            return i;
    return sizeof(int)*8;
}

void build() {
    h = get_h(n);
    for (int i=0; i<n; ++i) {
        tr[i+n] = 2;
        tm[i+n] = INT_MAX; // all tm should set to INT_MAX
    }
    
    for (int i=n-1; i>0; --i) {
        refresh(i);
        tm[i] = INT_MAX;
    }
}

void apply(int i, int val, int _tm) {
    if (_tm > tm[i]) return;   // only use latest tag!
    tm[i] = _tm;
    tr[i] = 1 << val;
    if (i<n) tag[i] = val;
}

inline void release(int i) { 
    apply(ls(i), tag[i], tm[i]);
    apply(rs(i), tag[i], tm[i]);
    tag[i] = 0, tm[i] = INT_MAX;  // clear tag
}

void push(int i) {
    for (int s=h; s>0; --s) {
        int p = i >> s;
        if (tag[p]) release(p);
    }
}

void build(int i) {
    while (i>1) i>>=1, refresh(i);
}

void update(int l, int r, int val) {
    int l0 = l+n, r0 = r+n;
    for (l=l0, r=r0; l<r; l>>=1, r>>=1) {
        if (l&1) apply(l++, val, op);
        if (r&1) apply(--r, val, op);
    }
    // unlike range sum
    // we can't add from leaf to root
    // so push all the tags down from root to leaf, then rebuild the path
    push(l0), build(l0);
    push(r0-1), build(r0 - 1);
}

// count the # of 1 bit in x
// divide and conquer
int count1(int x) {
    x = (x & 0x55555555) + ((x>>1) & 0x55555555);
    x = (x & 0x33333333) + ((x>>2) & 0x33333333);
    x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x>>8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + ((x>>16) & 0x0000ffff);
    return x;
}

int query(int l, int r) {
    int cnt = 0;
    for (push(l+=n), push((r+=n)-1); l<r; l>>=1, r>>=1) {
        if (l&1) cnt |= tr[l++];
        if (r&1) cnt |= tr[--r];
    }
    return count1(cnt);
}

int main() {
    scanf("%d %d %d\n", &n, &t, &op);

    build();

    {
        char ch;
        int a, b, c;
        while (op--) {
            scanf("%c ", &ch);
            if (ch == 'C') {
                scanf("%d %d %d\n", &a, &b, &c);
                if (a>b) swap(a, b);
                update(a-1, b, c);
            } else {
                scanf("%d %d\n", &a, &b);
                if (a>b) swap(a, b);
                printf("%d\n", query(a-1, b));
            }
        }
    }
    return 0;
}