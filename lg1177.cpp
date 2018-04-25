#include <cstdio>
#include <algorithm>

using namespace std;

void sort(int a[], int l, int r) {
    // classic
    // int i=l, j=r, x=a[l+rand()%(r-l+1)];
    // do {
    //     while (a[i]<x) ++i;
    //     while (a[j]>x) --j;
    //     if (i<=j) swap(a[i++], a[j--]);
    // } while (i<=j);
    // if (i<r) sort(a, i, r);
    // if (l<j) sort(a, l, j);

    // 3-way partition
    int i=l, j=l, k=r, x=a[l+rand()%(r-l+1)];
    while (j<=k)
        if (a[j]<x)
            swap(a[i++], a[j++]);
        else if (a[j]>x)
            swap(a[j], a[k--]);
        else
            ++j;
    if (l<i) sort(a, l, i);
    if (j<r) sort(a, j, r);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1];
    for (int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a, 1, n);
    for (int i=1; i<=n; ++i) printf("%d ", a[i]);
    return 0;
}