#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int n, m;
vector<int> a;

int partition(const vector<int>& a, int dis) {
    int cnt = 0;
    for (int j,i=0; i<a.size(); ) {
        ++cnt;
        for (j=i+1; j<a.size() && a[j]-a[i]<dis; ++j);
        i = j;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int l = 1, r = a.back()-a.front();
    while (l<r) {
        int mid = l + ((r-l)>>1);
        if (partition(a, mid) < m)
            r = mid - 1;
        else {
            l = mid;
            if (r == l+1) 
                if (partition(a, r)>=m) 
                    l = r;
                else
                    r = l;
            else {}
        }
    }

    cout << l << endl;

    return 0;
}