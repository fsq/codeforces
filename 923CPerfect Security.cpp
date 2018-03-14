#include <vector>
#include <cstdio>
#define cind(x) scanf("%d", &x)

using namespace std;

int n;
int msg[300007];
int root = 0, tn = 0;

class Node {
public:
    int cnt;
    int s[2];
    Node() {
        cnt = s[0] = s[1] = 0;
    }
} t[10000007];

void insert(int val) {
    int n = root;
    for (int i=31; i>=0; --i) {
        int b = val >> i & 1;
        if (!t[n].s[b]) {
            ++tn;
            t[n].s[b] = tn;
            t[tn].cnt = 1;
        } else 
            ++t[t[n].s[b]].cnt;
        n = t[n].s[b];
    }
}

int find(int val) {
    int n = root, res = 0;
    for (int i=31; i>=0; --i) {
        int b = val >> i & 1;
        int nxt;
        if (t[n].s[b]) 
            nxt = t[n].s[b];
        else {
            nxt = t[n].s[!b];
            res |= 1 << i;
        }
        if (--t[nxt].cnt==0) 
            t[n].s[t[n].s[1]==nxt] = 0;
        n = nxt;
        
    }
    return res;
}

int main() {
    cind(n);

    for (int i=0; i<n; ++i) 
        cind(msg[i]);

    for (int key, i=0; i<n; ++i) {
        cind(key);
        insert(key);
    }

    for (int i=0; i<n; ++i) {
        int res = find(msg[i]);
        printf("%d ", res);
    }
    printf("\n");

    return 0;
}