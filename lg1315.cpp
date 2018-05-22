/*
Consider each passenger i individually, time[i] = stop[ti] - arrive[i]
total cost = \sum stop[ti] - \sum arrive[i]
           = \sum_i^n w[i]*stop[i] - \sum arrive[i]
w[i] = #people get off at i

we call i overflow if stop[i]>lastest passenger at i
if we reduce di by 1, then stop[i+1] decreases by w[i+1]
if i+2 is again overflowing, then stop[i+2] decreases by w[i+2]...
until w[j+1] is not overflowing
*/

#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)

using namespace std;

const int N = 1007;

int go[N], // g[i] = time when bus leaves i 
    stp[N],// stp[i] = time when bus arrives i
    d[N],  // d[i] = time from i to i+1
    arv[N],// arv[i] = lastest psgner's arrival at i
    w[N],  // w[i] = #people leave at i
    prefix_w[N];
int n, acc;
int sum_of_arv = 0;
int zero_path = 0; // # d[i]=0

int rightmost_overflow[N], min_overflow[N];

void refresh() {
    go[1] = arv[1];
    REP(i, 2, n) {
        stp[i] = go[i-1] + d[i-1];
        go[i] = max(arv[i], stp[i]); 
    }
}

void init() {
    int m;
    scanf("%d %d %d", &n, &m, &acc);
    for (int i=1; i<n; ++i) {
        scanf("%d", &d[i]);
        if (d[i]==0) ++zero_path;
    }
    for (int a,s,t,i=0; i<m; ++i) {
        scanf("%d %d %d", &a, &s, &t);
        sum_of_arv += a;
        ++w[t];
        arv[s] = max(arv[s], a);
    }

    REP(i, 1, n+1) prefix_w[i] = prefix_w[i-1] + w[i];
    refresh();
}

inline bool overflow(int i) { return arv[i] < stp[i]; }

void preprocess() {
    rightmost_overflow[n+1] = 0;
    min_overflow[n+1] = INT_MAX;

    for (int i=n; i>0; --i) 
        if (overflow(i)) {
            rightmost_overflow[i] = rightmost_overflow[i+1] ? 
                                        rightmost_overflow[i+1] : i;
            min_overflow[i] = min(min_overflow[i+1], stp[i]-arv[i]);
        } else {
            rightmost_overflow[i] = 0;
            min_overflow[i] = INT_MAX;
        }
}

int main() {
    init();
    // while we can use an accelerator on some non-zero path
    while (acc && !(zero_path==n-1)) {
        preprocess();

        int vmax=0, cmax, imax;
        REP(i, 1, n-1) 
            if (!d[i])
                continue;  
            else {
                int v, c;
                if (!overflow(i+1))
                    v = w[i+1], c = d[i];
                else {
                    int j = rightmost_overflow[i+1];
                    v = prefix_w[j+1] - prefix_w[i]; // [i+1,j] overflow, add w[i+1, j+1]
                    c = min(d[i], min_overflow[i+1]);
                }
                if (v>vmax) {
                    vmax = v;
                    cmax = c;
                    imax = i;
                }
            }

        int k = min(acc, cmax);
        d[imax] -= k;
        acc -= k;

        if (d[imax]==0) ++zero_path;
        refresh();
    }

    int sum = 0;
    for (int i=1; i<=n; ++i) sum += w[i] * stp[i];
    printf("%d\n", sum - sum_of_arv);
    return 0;
}