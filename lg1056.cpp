#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int m,n,k,l,d;
int r[1007], c[1007];

int main() {
    cin  >> m >> n >> k >> l >> d;
    for (int x,y,p,q,_t=0; _t<d; ++_t) {
        cin >> x >> y >> p >> q;
        if (x==p)
            ++c[min(y, q)];
        else
            ++r[min(x, p)];
    }

    vector<pair<int,int>> a;

    for (int i=1; i<=m; ++i)
        if (r[i])
            a.push_back({r[i], i});
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    a.resize(k);
    sort(a.begin(), a.end(), [](const pair<int,int>& a, const pair<int,int>& b){return a.second<b.second; });
    for_each(a.begin(), a.end(), [](const pair<int,int>& a) {printf("%d ", a.second );});
    printf("\n");


    a.clear();    
    for (int i=1; i<=n; ++i) 
        if (c[i])
            a.push_back({c[i], i});
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    a.resize(l);
    sort(a.begin(), a.end(), [](const pair<int,int>& a, const pair<int,int>& b){return a.second<b.second; });
    for_each(a.begin(), a.end(), [](const pair<int,int>& a) {printf("%d ", a.second );});

    return 0;
}