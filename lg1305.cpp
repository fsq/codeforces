#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string s[27];
int shown[27];

void dfs(int x) {
    printf("%c", x+'a');
    if (s[x][1]!='*') dfs(s[x][1]-'a');
    if (s[x][2]!='*') dfs(s[x][2]-'a');
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        string t;
        cin >> t;
        s[t[0]-'a'] = t;
        for (int j=0; j<3; ++j)
            if (t[j]!='*')
                ++shown[t[j]-'a'];
    }

    int rt = find_if(shown, shown+26, [](int x) { return x==1; }) - shown;
    dfs(rt);
    return 0;
}
