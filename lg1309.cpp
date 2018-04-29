#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

vector<int> s, w;

bool cmp(const int x, const int y) {
    return s[x]>s[y] || (s[x]==s[y] && x<y);    
}

int main() {
    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);
    // vector<int> s, w;
    // auto cmp  = [&w,&s](const int x, const int y) {
    //                 return s[x]>s[y] || (s[x]==s[y] && x<y);
    //             };


    s.resize(n<<1), w.resize(n<<1);
    for (int i=0; i<(n<<1); ++i) scanf("%d", &s[i]);
    for (int i=0; i<(n<<1); ++i) scanf("%d", &w[i]);
    vector<int> a(n<<1);
    iota(a.begin(), a.end(), 0);


    sort(a.begin(), a.end(), cmp);

    vector<int> win(n), los(n);
    while (r--) {
        for (int i=0; i<(n<<1); i+=2) 
            if (w[a[i]]>w[a[i+1]]) {
                ++s[a[i]];
                win[i>>1] = a[i], los[i>>1] = a[i+1];
            } else {
                ++s[a[i+1]];
                win[i>>1] = a[i+1], los[i>>1] = a[i];
            }

        // ~3200ms and tle one case using anonymous function
        // ~2400ms using predefined function
        merge(win.begin(), win.end(), los.begin(), los.end(), a.begin(), cmp);

        // ~2000ms
        // reinvent merge
        // int i=0, j=0, p=0;
        // while (i<n && j<n) 
        //     a[p++] = cmp(win[i], los[j]) ? win[i++] : los[j++];
        // while (i<n) a[p++] = win[i++];
        // while (j<n) a[p++] = los[j++];

    }
    printf("%d\n", a[q-1]+1);

    return 0;
}