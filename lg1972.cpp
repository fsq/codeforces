#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m;
int a[500007], pre[1000007];

inline int lowbit(int x) { return x & -x; }

void update(vector<int>& s, int p, int v) {
    for (; p<s.size(); p+=lowbit(p)) s[p] += v;
}

int sum(vector<int>& s, int i) {
    int ret = 0;
    for (; i; i-=lowbit(i)) ret += s[i];
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) scanf("%d", &a[i]);

    scanf("%d", &m);
    vector<pair<pair<int,int>, int>> q;
    for (int l,r,i=0; i<m; ++i) {
        scanf("%d %d", &l, &r);
        q.push_back({{l, r}, i});
    }

    sort(q.begin(), q.end(), [](const pair<pair<int,int>, int>& a, 
                                const pair<pair<int,int>, int>& b) {
        return a.first.second < b.first.second;
    });

    vector<int> s(n+1);
    vector<int> ans(m);

    for (int r=1, i=0; i<q.size(); ++i) {
        for (; r<=q[i].first.second; ++r) { 
            if (pre[a[r]]) 
                update(s, pre[a[r]], -1);
            update(s, pre[a[r]]=r, 1);
        }
        ans[q[i].second] = sum(s, q[i].first.second) - sum(s, q[i].first.first-1);
    }

    for (auto x : ans) printf("%d\n", x);

    return 0;
}