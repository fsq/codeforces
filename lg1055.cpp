#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string s;
    string ori;
    cin >> ori;
    for (auto c : ori)
        if (c!='-') 
            s.push_back(c);

    char c = s.back();
    s.pop_back();

    int sum;
    for (int i=1; i<=s.size(); ++i)
        sum += i * (s[i-1]-'0');
    sum %= 11;

    char ans = sum==10 ? 'X' : sum+'0';

    if (ans==c) 
        printf("Right\n");
    else {
        ori.pop_back();
        ori.push_back(ans);
        cout << ori << endl;
    }
    return 0;
}