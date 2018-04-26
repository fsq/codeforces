#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int m, n, x;
    cin >> m >> n;

    unordered_set<int> st;
    queue<int> mem;
    int ans = 0;
    for (int _t=0; _t<n; ++_t) {
        cin >> x;
        if (st.find(x)==st.end()) {
            ++ans;
            if (mem.size()==m) {
                int p = mem.front();
                mem.pop();
                st.erase(p);
            }
            st.insert(x);
            mem.push(x);
        } 
    }

    printf("%d", ans);
    return 0;
}