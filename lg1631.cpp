#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a, b;
    for (int x,i=0; i<n; ++i) scanf("%d", &x), a.push_back(x);
    for (int x,i=0; i<n; ++i) scanf("%d", &x), b.push_back(x);

    multiset<pair<int, pair<int,int>>> st;
    for (int i=0; i<n; ++i) st.insert({a[i]+b[0], {i, 0}});

    for (int t=0; t<n; ++t) {
        printf("%d ", st.begin()->first);
        int i=st.begin()->second.first, j=st.begin()->second.second;
        st.erase(st.begin());
        if (++j<n) st.insert({a[i]+b[j], {i, j}});
    }

    return 0;
}