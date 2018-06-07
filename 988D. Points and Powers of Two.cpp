#include <vector>
#include <cstdio>
#include <algorithm>
#define ALL(x) x.begin(), x.end()

using namespace std;

int n;
vector<int> a;
vector<pair<int,int>> st;

int main() {
    scanf("%d", &n);
    st.resize(n), a.resize(n);
    
    for (int i=0; i<n; ++i) {
        scanf("%d", &a[i]);
        st[i] = {a[i], i};
    }

    sort(st.begin(), st.end());

    vector<int> ans2;

    for (int i=0; i<n; ++i) {
        long long x = a[i];
        for (long long d=1; x+d<=1e9; d<<=1) {
            long long y = x + d, z = y + d;
            auto ity = upper_bound(ALL(st), pair<int,int>{y, -1});
            auto itz = upper_bound(ALL(st), pair<int,int>{z, -1});

            if (ity!=st.end() && ity->first==y && 
                z<INT_MAX && itz!=st.end() && itz->first==z) {
                printf("3\n%lld %lld %lld\n", x, y, z);
                return 0;
            }
            if (ans2.empty() && ity!=st.end() && ity->first==y)
                ans2 = {(int)x, (int)y};
        }
    }

    if (ans2.empty())
        printf("1\n%d\n", a[0]);
    else 
        printf("2\n%d %d\n", ans2[0], ans2[1]);

    return 0;
}