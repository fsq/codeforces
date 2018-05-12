#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

struct Eq {
    int a, b, c, x;
    Eq(int _a, int _b, int _c): a(_a), b(_b), c(_c), x(1) {}
    int eval() {
        int ret = a*x*x + b*x + c;
        ++x;
        return ret;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<Eq> eq;
    for (int a,b,c,i=0; i<n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        eq.emplace_back(a, b, c);
    }

    priority_queue<pair<int,int>, 
            vector<pair<int,int>>, greater<pair<int,int>>> q;
    for (int i=0; i<n; ++i)
        q.push({eq[i].eval(), i});

    while (m--) {
        printf("%d ", q.top().first);
        int i = q.top().second;
        q.pop();
        q.push({eq[i].eval(), i});
    }

    // multiset<pair<int,int>> st;
    // for (int i=0; i<n; ++i)
    //     st.insert({eq[i].eval(), i});

    // while (m--) {
    //     printf("%d ", st.begin()->first);
    //     int i = st.begin()->second;
    //     st.erase(st.begin());
    //     st.insert({eq[i].eval(), i});
    // }

    return 0;
}