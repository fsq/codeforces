#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
vector<int> fa;

int find(int x ) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    fa = vector<int>(n+1, 0);
    vector<int> pa(n+1, 0);
    iota(fa.begin(), fa.end(), 0);

    int root = -1, res = 0, ans = 0;
    for (int i=1, j; i<=n; ++i) {
        cin >> j;
        pa[i] = j;
        if (i==j)
            root = i;
    }
    for (int j, i=1; i<=n; ++i)  {
        j = pa[i];
        if (i==j)
            continue;
        int fx = find(i), fy = find(j);
        if (fx != fy)
            fa[fx] = fy;
        else {
            ++ans;
            // in this case fx must be i
            // bcz previously shown i must be parents of other nodes
            if (root==-1) {
                fa[fx] = fx;
                pa[fx] = fx;
                root = fx;
            } else {
                fa[fx] = root;
                pa[fx] = root;
            }
        }
    }
    int cnt_roots = 0;
    for (int i=1; i<=n; ++i) 
        if (find(i)==i)
            ++cnt_roots;
    
    cout << ans + cnt_roots - 1 << '\n';
    for (int i=1; i<n; ++i)
        cout << (fa[i]==i ? root : pa[i]) << ' ';
    cout << (fa[n]==n ? root : pa[n]) << endl;
    return 0;
}