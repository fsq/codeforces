#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> a, b;

pair<int,int> match(int a, int b) {
    pair<int,int> res;
    if (a>b) {
        res = match(b, a);
        swap(res.first, res.second);
        return res;
    }

    if (a==b) return {0, 0};

    if (a==0) {
        if (b==1 || b==4) res = {0, 1};
                   else   res = {1, 0};
    } else if (a==1) {
        if (b==2 || b==4) res = {0, 1};
                   else   res = {1, 0};
    } else if (a==2) {
        if (b==3) res = {0, 1};
            else  res = {1, 0};
    } else res = {1, 0};

    return res;
}

int main() {
    int n, na, nb;
    cin >> n >> na >> nb;

    for (int x,i=0; i<na; ++i) {
        cin >> x;
        a.push_back(x);
    }
    for (int x,i=0; i<nb; ++i) {
        cin >> x;
        b.push_back(x);
    }

    int xans=0, yans=0, p=0, q=0;
    for (int i=0; i<n; ++i) {
        auto sc = match(a[p++], b[q++]);
        xans += sc.first;
        yans += sc.second;
        if (p==a.size()) p = 0;
        if (q==b.size()) q = 0;
    }

    printf("%d %d\n", xans, yans);

    return 0;
}