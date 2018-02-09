#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> cache(n+1, vector<int>(26, -1));

    while (q--) {
        int m;
        char c;
        cin >> m >> c;

        if (cache[m][c-'a']!=-1)
            cout << cache[m][c-'a'] << '\n';
        else {
            int& ans = cache[m][c-'a'];

            int start=0;
            int modified = 0;

            for (int end=0; end<n; ++end) {
                if (s[end]!=c && ++modified>m) 
                    while (modified>m)
                        if (s[start++]!=c)
                            --modified;
                ans = max(ans, end-start+1);
            }

            cout << ans << '\n';
        }

    }

    return 0;
}