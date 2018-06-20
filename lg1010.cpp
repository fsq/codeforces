#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string f(int x) {
    if (x==1) return "2";
    if (x==0) return "0";
    string ans;
    for (int i=0; x; x>>=1, ++i)
        if (x & 1)
            if (i==1) ans = "2+" + ans;
            else      ans = "2(" + f(i) + ")" + "+" + ans;
        else {}
    ans.pop_back();
    return ans;
}

int main() {
    int n; 
    cin >> n;
    cout <<f(n) << endl;
    return 0;
}
