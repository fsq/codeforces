#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gems = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
vector<string> color = {"purple", "green", "blue", "orange", "red", "yellow"};

int main() {
    int n;
    cin >> n; 
    {
        string s;
        for (int i=0; i<n; ++i) {
            cin >> s;
            for (auto& t : color)
                if (t==s) 
                    t = ".";
        }
    }

    int cnt = 0;
    for (auto& s : color)
        if (s!=".") ++cnt;

    cout << cnt << '\n';
    for (int i=0; i<6; ++i)
        if (color[i]!=".")
            cout << gems[i] << '\n';

    return 0;
}