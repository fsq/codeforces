#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#define ALL(a) a.begin(),a.end()

using namespace std;
string ans, s;
int p1, p2, p3;

bool valid(char a, char b) {
    return a<b && ((islower(a) && islower(b)) || (isdigit(a) && isdigit(b)));
}

string expand(char a, char b) {
    string ret;
    for (char c=a+1; c<b; ++c) 
        if (p1==3)
            ret += string(p2, '*');
        else if (isdigit(c))
            ret += string(p2, c);
        else 
            ret += string(p2, p1==1 ? tolower(c) : toupper(c));
    if (p3==2) reverse(ALL(ret));
    return a + ret;
}

int main() {
    cin >> p1 >> p2 >> p3 >> s;
    for (int i=0; i<s.size(); ) 
        if (i+1==s.size() || s[i+1]!='-') 
            ans.push_back(s[i++]);
        else if (i+2<s.size() && valid(s[i], s[i+2])) {
            ans += expand(s[i], s[i+2]);
            // a-d-e
            i += 2;
        } else 
            ans.push_back(s[i++]);
    cout << ans << endl;
    return 0;
}