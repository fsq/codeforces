#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

vector<int> fa;

int find(int x) {
    return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;
    fa.resize(n+1);
    iota(fa.begin(), fa.end(), 0);

    for (int z,x,y,i=0; i<m; ++i) {
        cin >> z >> x >> y;
        if (z==1) 
            fa[find(x)] = find(y);
        else 
            cout << (find(x)==find(y) ? "Y" : "N" ) << '\n';
        
    }
    return 0;
}