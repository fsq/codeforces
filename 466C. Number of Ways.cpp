#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a;

    {
        long long t;
        for (int i=0; i<n; ++i) {
            cin >> t;
            a.push_back(t);
        }
    }

    unordered_map<long long, long long> st;
    long long sum = accumulate(a.begin(), a.end(), (long long)0);

    long long suf_sum = a.back();
    long long ans = 0;
    for (int i=a.size()-2; i>=0; --i) {
        long long s = sum - suf_sum;
        suf_sum += a[i];
        if (s*3==sum && st.find(s*2)!=st.end())
            ans += st[s*2];
        ++st[s];
    }
    cout << ans << endl;
    return 0;
}