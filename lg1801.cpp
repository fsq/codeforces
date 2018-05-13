#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> snd;
priority_queue<int> fst;
int sz = 1;
int a[200003], b[200003];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=0; i<n; ++i) scanf("%d", &a[i]);
    for (int i=0; i<m; ++i) scanf("%d", &b[i]);
    
    for (int j=0,i=0; j<m; ) {
        while (i<b[j]) {
            if (fst.empty() || a[i]<=fst.top()) 
                fst.push(a[i]);
            else      
                snd.push(a[i]);
            ++i;
        }

        while (fst.size()>sz) snd.push(fst.top()), fst.pop();
        while (fst.size()<sz) fst.push(snd.top()), snd.pop();

        printf("%d\n", fst.top());
        ++j;
        ++sz;
    }

    return 0;
}