#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int move(const string& s, char a, char b) {
    if ((a==b && count(s.begin(), s.end(), a)<2) || 
        (a!=b && (!count(s.begin(), s.end(), a) || !count(s.begin(), s.end(), b)))) 
        return INT_MAX;

    int n = s.size(), ans = INT_MAX;
    for (int i=0; i<n; ++i) 
        if (s[i]==b) {
            string t = s;
            t.erase(t.begin()+i);
            t.push_back(b);
            int fst = n - 1 - i;

            for (int j=0; j+1<n; ++j)
                if (t[j]==a) {
                    int cnt = fst + abs(n - 2 - j);

                    string v = t;
                    v.erase(v.begin()+j);
                    v.insert(v.begin()+n-2, a);

                    if (v[0]=='0') {
                        int k;
                        for (k=0; k<n; ++k) if (v[k]!='0') break;
                        if (k>=n-2) cnt = INT_MAX;
                               else cnt += k;
                    }

                    ans = min(ans, cnt);
                }
        }
    // printf("%c %c %d\n", a,b,ans);
    return ans;
}

int main() {
    string s;
    cin >> s;

    int ans = min(min(move(s, '0', '0'), move(s, '2', '5')),
                  min(move(s, '5', '0'), move(s, '7', '5')));
    cout << (ans==INT_MAX ? -1 : ans) << endl;

    return 0;
}