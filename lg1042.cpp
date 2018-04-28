#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> ans11, ans21;

void a11(int &x, int &y, bool win) {
    if (win) ++x; else ++y;
    int mn = min(x, y), mx = max(x, y);
    if (mx>=11 && mx-mn>=2) {
        ans11.push_back(to_string(x) + ":" + to_string(y));
        x = y = 0;
    }
}

void a21(int &x, int &y, bool win) {
    if (win) ++x; else ++y;
    int mn = min(x, y), mx = max(x, y);
    if (mx>=21 && mx-mn>=2) {
        ans21.push_back(to_string(x) + ":" + to_string(y));
        x = y = 0;
    }
}

int main() {
    char c;
    int x=0, y=0, x1=0, y1=0;
    while (scanf("%c", &c)!=EOF) {
        if (!isalpha(c)) continue;
        if (c=='E') {
            ans11.push_back(to_string(x) + ":" + to_string(y));
            ans21.push_back(to_string(x1) + ":" + to_string(y1));
            break;
        }

        a11(x,  y,  c=='W');
        a21(x1, y1, c=='W');
    }
    for (auto s : ans11)
        cout << s << '\n';
    cout << '\n';
    for (auto s : ans21)
        cout << s << '\n';

    return 0;
}