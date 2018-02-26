#include <iostream>
#include <vector>

using namespace std;

// using PII = pair<int, int>;
typedef pair<int,int> PII;
int n, q;
vector<PII> t;  // min max

inline int ls(int i) { return i<<1; }
inline int rs(int i) { return i<<1 | 1; }
void refresh(int i) {
    t[i].first = min(t[ls(i)].first, t[rs(i)].first);
    t[i].second = max(t[ls(i)].second, t[rs(i)].second);
}


void build() {
    t = vector<PII>(n<<1 | 1, PII(INT_MAX, INT_MIN));
    for (int j,i=0; i<n; ++i) {
        scanf("%d", &j);
        t[i+n] = PII(j, j);
    }
    for (int i=n-1; i>0; --i)
        refresh(i);
}

int query(int l, int r) {
    int max_elem = INT_MIN, min_elem = INT_MAX;

    for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
        if (l&1) {
            max_elem = max(max_elem, t[l].second);
            min_elem = min(min_elem, t[l].first);
            ++l;
        } 
        if (r&1) {
            --r;
            max_elem = max(max_elem, t[r].second);
            min_elem = min(min_elem, t[r].first);
        }
    }
    return max_elem - min_elem;
}

int main() {
    scanf("%d %d", &n, &q);

    build();
    for (int l,r,i=0; i<q; ++i) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l-1, r));
    }

    return 0;
}