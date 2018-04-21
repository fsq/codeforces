#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

// 这道题会出现重边，所以用set统计度数会出错，必须用multiset
unordered_map<char, multiset<char>> e;
int n;

void print(char u, vector<int>& p) {
    auto& to = e[u];
    while (!to.empty()) {
        auto nxt = *to.begin();
        to.erase(nxt);
        e[nxt].erase(u);
        print(nxt, p);
    }
    p.push_back(u);
}

int main() {
    scanf("%d\n", &n);
    char minchar = 'z';
    {
        char u, v;
        for (int i=1; i<=n; ++i) {
            scanf("%c%c\n", &u, &v);
            e[u].insert(v);
            e[v].insert(u);
            minchar = min(minchar, min(u, v));
        }
    }

    vector<char> odd;
    for (auto &kv : e) 
        if (kv.second.size() & 1) odd.push_back(kv.first);

    if (! (odd.size()==0 || odd.size()==2))
        printf("No Solution\n");
    else {
        if (!odd.empty())
            minchar = min(odd[0], odd[1]);
        vector<int> path;
        print(minchar, path);
        for (int i=path.size()-1; i>=0; --i) printf("%c", path[i]);
        printf("\n");
    }



    return 0;
}