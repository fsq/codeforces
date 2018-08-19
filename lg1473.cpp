#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <numeric>

using namespace std;

int n;
vector<string> ans;

void dfs(vector<int>& a, string eq, int x) {
    if (x==n+1) {
        if (accumulate(a.begin(), a.end(), 0)==0) ans.push_back(eq);
    } else {
        int old = a.back();
        a.back() = old>0 ? old*10+x : old*10-x;
        dfs(a, eq+" "+to_string(x), x+1);
        a.back() = old;

         a.push_back(x);
        dfs(a, eq+"+"+to_string(x), x+1);
        a.pop_back();

        a.push_back(-x);
        dfs(a, eq+"-"+to_string(x), x+1);
        a.pop_back();
    }
}

int main() {
    cin >> n;
    vector<int> a = {1};
    string eq = "1";
    dfs(a, eq , 2);

    for (auto& s : ans)
        cout << s << '\n';
    return 0;
}