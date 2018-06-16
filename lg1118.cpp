#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, sum;
bool found = false;
vector<int> ans;

vector<int> get_w(int n) {
    vector<int> w(n);
    w[0] = 1;
    for (int i=1; i<n; ++i) 
        for (int j=i; j>0; --j) w[j] += w[j-1];
    return w;
}

bool dfs(vector<int>& w, vector<int>& a, int i, int used, int sum) {
    if (sum==0)
        if (i==w.size()) {
            ans = move(a);
            return true;
        } else 
            return false;
    else if (i<w.size()) 
        for (int j=0; j<w.size() && (j+1)*w[i]<=sum; ++j) 
            if (!(used>>j & 1)) {
                a.push_back(j+1);
                if (dfs(w, a, i+1, used | (1<<j), sum-(j+1)*w[i])) return true;
                a.pop_back();
            }
    return false;
}

int main() {
    cin >> n >> sum;
    auto w = get_w(n);

    vector<int> s;
    dfs(w, s, 0, 0, sum);

    if (!ans.empty()) {
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }

    return 0;
}