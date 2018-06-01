#include <string>
#include <iostream>

using namespace std;

int map[256], use[256];

int main() {
    string s, t, a;
    cin >> s >> t >> a;

    for (int i=0; i<s.size(); ++i)
        if ((map[s[i]] && map[s[i]]!=t[i]) || (use[t[i]] && use[t[i]]!=s[i])) {
            cout << "Failed" << endl;
            return 0;
        } else {
            map[s[i]] = t[i];
            use[t[i]] = s[i];
        }

    for (char c='A'; c<='Z'; ++c)
        if (!map[c] || !use[c]) {
            cout << "Failed" << endl;
            return 0;
        }

    for (auto& c : a) c = map[c];
    cout << a << endl;    

    return 0;
}