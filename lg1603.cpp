#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> num = {"one", "two", "three", "four", "five", "six", 
                     "seven", "eight", "nine", "ten", "eleven", "twelve",
                     "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                     "eighteen", "nineteen", "twenty", "a", "both", "another",
                     "first", "second", "third"};
vector<int> code = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};

int main() {
    vector<string> a;
    {
        string s;
        for (int i=0; i<6; ++i) {
            cin >> s;
            auto it = find(num.begin(), num.end(), s) - num.begin();
            if (it!=num.size()) {
                int t = code[it]*code[it] % 100;
                auto s = t<=9 ? "0"+to_string(t) : to_string(t);
                a.push_back(s);
            }
        }
    }

    sort(a.begin(), a.end());
    string ans;
    for (auto s : a) ans += s;
    while (ans.size() && ans[0]=='0') ans.erase(ans.begin());
    cout << (ans.empty() ? "0" : ans) << endl;


    return 0;
}