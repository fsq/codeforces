#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
 
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];

    unordered_set<int> st;
    vector<int> s(n+1);
    for (int i=1; i<=n; ++i)
        if (st.find(a[i])==st.end()) {
            ++s[i];
            st.insert(a[i]);
        }

    partial_sum(s.begin(), s.end(), s.begin());

    st.clear();
    long long ans = 0;
    for (int i=n; i>0; --i)
        if (st.find(a[i])==st.end()) {
            ans += s[i-1];
            st.insert(a[i]);
        }

    cout << ans << endl;
    return 0;

}