#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string ans(n, 'o');
    int a, b;
    a = b = 1;
    while (a<=n) {
        ans[a-1] = 'O';
        int nxt = a + b;
        a = b;
        b = nxt;
    }  
    printf("%s\n", ans.c_str());
    return 0;
}