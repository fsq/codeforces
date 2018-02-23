#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <unordered_map>

using namespace std;

vector<long long> a;
vector<pair<long long,int>> tree; // sum max
vector<int> d;


inline int get_mid(int l, int r) { return (l+r) >> 1; }
inline int left_son(int x) { return x<<1; }
inline int right_son(int x) { return (x<<1) + 1; }
inline void refresh(int now) {
    tree[now].first = tree[left_son(now)].first + tree[right_son(now)].first;
    tree[now].second = max(tree[left_son(now)].second, tree[right_son(now)].second); 
}

void build(int now, int l, int r) {
    if (l == r) 
        tree[now] = {a[l], a[l]};
    else {
        int mid = get_mid(l, r);
        build(left_son(now), l, mid);
        build(right_son(now), mid+1, r);
        refresh(now);
    }
}

// query sum
long long query(int now, int l, int r, int start, int end) {
    if (start<=l && r<=end)
        return tree[now].first;
    else {
        int mid = get_mid(l, r);
        long long ret = 0;
        if (end>=mid+1) ret += query(right_son(now), mid+1, r, start, end);
        if (start<=mid) ret += query(left_son(now), l, mid, start, end);
        return ret;
    }
}

void update(int now, int l, int r, int start, int end) {
    if (tree[now].second<=2)
        return;
    if (l == r) 
        tree[now].first = tree[now].second = d[tree[now].first];
    else {
        int mid = get_mid(l, r);
        if (end>=mid+1) update(right_son(now), mid+1, r, start, end);
        if (start<=mid) update(left_son(now), l, mid, start, end);
        refresh(now);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long j;
    for (int i=0; i<n; ++i) {
        scanf("%I64d", &j);
        a.push_back(j);
    }

    tree = vector<pair<long long,int>>(n<<2, {0,INT_MIN});
    build(1, 0, n-1);

    d = vector<int>(tree[1].second+1, 0);
    for (int i = 1; i <= tree[1].second; i++) 
        for (int j = i; j <= tree[1].second; j += i) d[j]++;

    int t, l, r;
    while (m--) {
        scanf("%d %d %d", &t, &l, &r);
        --l, --r;
        if (t == 1) 
            update(1, 0, n-1, l, r);
        else {
            long long ans = query(1, 0, n-1, l, r);
            printf("%I64d\n", ans);
            // cout << ans << '\n';
        }
    }
    return 0;
}



// void find_primes(vector<int>& st, int maxn) {
//     vector<bool> a(maxn+1, true);
//     int i;
//     for (i=2; i<=sqrt(maxn); ++i) 
//         if (a[i]) {
//             d[i] = 2;
//             st.push_back(i);
//             for (int j=i*i; j<=maxn; j+=i)
//                 a[j] = false;
//         }
//     for (; i<=maxn; ++i) 
//         if (a[i]) {
//             d[i] = 2;
//             st.push_back(i);
//         }
// }

// int calc(int x) {
//     if (x<=2) return x;
//     if (d[x]!=0) return d[x];

//     int& res = d[x];
//     res = 1;
//     auto it = primes.begin();

//     while (x>1) {
//         int count = 0, div = *(it++);
//         while (x%div==0) {
//             x /= div;
//             ++count;
//         }
//         res *= (count + 1);
//     }

//     return res;
// }