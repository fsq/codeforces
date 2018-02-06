#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int to_int(const string& s) {
    int ind = 0;
    for (int i=0; i<s.size(); ++i)
        ind = ind*26 + s[i]-'A'+1;
    return ind;
}

string to_str(const string& s) {
    int ind = stoi(s);
    string ret;
    while (ind) 
        if (ind%26==0) {
            ret.push_back('Z');
            ind = ind/26 - 1;
        }
        else {
            ret.push_back('A'+ind%26-1);
            ind /= 26;
        }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    while (n--) {
        string now;
        cin >> now;
        string s1, a1, s2, a2;
        int i = 0;
        while (i<now.size() && !isdigit(now[i])) s1.push_back(now[i++]);
        while (i<now.size() && isdigit(now[i])) a1.push_back(now[i++]);
        while (i<now.size() && !isdigit(now[i])) s2.push_back(now[i++]);
        while (i<now.size() && isdigit(now[i])) a2.push_back(now[i++]);
        // cout << s1 << ' ' << a1<<endl;
        if (s2.empty()) {
            cout << "R" + a1 + "C" + to_string(to_int(s1)) << '\n';
        } else {
            cout << to_str(a2) + a1 << '\n';
        }
    }
    return 0;
}