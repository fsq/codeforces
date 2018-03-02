#include <vector>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int h1, a1, c1, h2, a2;
    scanf("%d %d %d %d %d", &h1, &a1, &c1, &h2, &a2);

    vector<string> ans;
    while (h2>0) {
        if (h1>a2 || h2<=a1) {
            ans.push_back("STRIKE");
            h2 -= a1;
            h1 -= a2;
        } else {
            ans.push_back("HEAL");
            h1 += c1;
            h1 -= a2;
        }
    }
    printf("%lu\n", ans.size());
    for (int i=0; i<ans.size(); ++i)
        printf("%s\n", ans[i].c_str());

    return 0;
}