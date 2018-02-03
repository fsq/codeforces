#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    string num;
    cin >> num;
    unordered_set<int> f;
    f.insert(0);
    vector<string> ans(8, "");
    bool has0 = false;
    for (auto c : num) {
        int dig = c - '0';
        vector<int> add_digits;
        for (auto prev : f) {
            int next_dig = (prev*10 + dig) % 8;
            if (ans[next_dig].empty())
                ans[next_dig] = ans[prev] + c;
            if (next_dig==0) {
                has0 = true;
                break;
            }
            add_digits.push_back(next_dig);
        }
        f.insert(add_digits.begin(), add_digits.end());
        if (has0)
            break;
    }
    if (has0)
        cout << "YES" << endl << ans[0] << endl;
    else
        cout << "NO" << endl;
    return 0;
}