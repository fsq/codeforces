#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// typedef pair<int,int> PII;
vector<int> a;
// vector<vector<PII> > s;
// don't use vector here
// constant matters in this prblem
int mx[100000][20], mi[100000][20];
int n, h, q;

void build() {
    scanf("%d %d", &n, &q);
    h = log(1.0*n) / log(2.0);

    for (int j,i=0; i<n; ++i) {
        scanf("%d", &j);
        a.push_back(j);
        mx[i][0] = mi[i][0] = a[i];
    }

    for (int p=1; p<=h; ++p) 
        for (int i=0; i+(1<<p)-1<n; ++i) {
            mi[i][p] = min(mi[i][p-1], mi[i+(1<<(p-1))][p-1]);
            mx[i][p] = max(mx[i][p-1], mx[i+(1<<(p-1))][p-1]);
        }
}

int query(int l, int r) { // [l, r)
    int p = log(1.0*r-l) / log(2.0);
    int min_elem = min(mi[l][p], mi[r-(1<<p)][p]);
    int max_elem = max(mx[l][p], mx[r-(1<<p)][p]);
    return max_elem - min_elem;
}

int main() {

    build();

    for (int l,r,i=0; i<q; ++i) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l-1, r));
    }

    return 0;
}