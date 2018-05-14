#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s;
    cin >> s;   
    s.pop_back();
    int n = s.size();

    stack<long long> num;
    char c;
    int i = 0;
    while (i<n) {
        if (isdigit(s[i])) {
            int j = i;
            while (i<n && s[i]!='.') ++i;
            num.push(stoll(s.substr(j, i-j)));
        } else {
            auto b = num.top(); num.pop();
            auto a = num.top(); num.pop();
            if (s[i]=='+') {
                num.push(a + b);
            } else if (s[i]=='-') {
                num.push(a - b);
            } else if (s[i]=='*') {
                num.push(a * b);
            } else {
                num.push(a / b);
            }
        }
        ++i;
    }
    printf("%lld\n", num.top());
    return 0;
}