#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;

    int base = a / b;
    a %= b;

    string s;
    unordered_map<int, int> pos;
    pos[a] = 0;
    a *= 10;
    while (a) {
        s.push_back(a/b + '0');
        a %= b;
        if (pos.count(a)) {
            s = s.substr(0, pos[a]) + '(' + s.substr(pos[a]) + ')';
            break;
        } else {
            pos[a] = s.size();
            a *= 10;
        }
    }
    if (s.empty()) s = "0";
    string ans = to_string(base) + "." + s;
    for (int i=0,j=0; i<ans.size(); ++i) {
        cout << ans[i];
        if (++j==76) {
            cout << '\n';
            j = 0;
        }
    }
    cout << endl;
    return 0;
}