#include <string>
#include <iostream>
#include <vector>

using namespace std;

int count(const string& s, int t) {
    vector<int> cnt(256);
    for (auto c : s) ++cnt[c];

    int ans = 0;
    for (auto c : s)
        if (cnt[c]+t <= s.size())
            ans = max<int>(ans, cnt[c] + t);
        else 
            ans = max<int>(ans, s.size()-(t==1)); // be careful ! eg. aaaaaaa n=1
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    int t;
    cin >> t;


    int a[3];
    {
        string s;
        for (int i=0; i<3; ++i) {
            cin >> s;
            a[i] = count(s, t);
        }
    }

    int mx = max(a[0], max(a[1], a[2]));
    int cnt = 0;
    for (int i=0; i<3; ++i) if (a[i]==mx) ++cnt;

    if (cnt>1)
        cout << "Draw" << endl;
    else if (mx==a[0])
        cout << "Kuro" << endl;
    else if (mx==a[1])
        cout << "Shiro" << endl;
    else 
        cout << "Katie" << endl;


    return 0;
}