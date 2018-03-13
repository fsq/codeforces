#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define cind(x) scanf("%d", &x)

using namespace std;

int n, m;

class Edge {
public:
    int len;
    int index;
    Edge(int l, int i):len(l),index(i){ }
    Edge() {}
};

vector<Edge> t(1), e(1);
vector<int> pos;
vector<pair<int,int>> ans;

static bool cmp(const Edge& e1, const Edge& e2) {
    return e1.len < e2.len;
}

int main() {
    cind(n), cind(m);
    for (int l,c,i=1; i<=m; ++i) {
        cind(l), cind(c);
        if (c==0)
            e.push_back(Edge(l, i));
        else
            t.push_back(Edge(l, i));
    }

    sort(t.begin()+1, t.end(), cmp);
    sort(e.begin()+1, e.end(), cmp);

    multiset<pair<int,int>> st;

    ans = vector<pair<int,int>>(m+1, {0, 0});
    pos = vector<int>(t.size()+1, 0);
    for (int i=1; i<t.size(); ++i) {
        pos[i] = i + 1;
        if (pos[i]<t.size()) 
            st.insert({max(t[i].len, t[pos[i]].len), i});
        ans[t[i].index] = {1, i+1};
    }


    for (int ei=1; ei<e.size(); ++ei) {
        auto& x = e[ei];
        auto pr = *st.begin();
        st.erase(st.begin());
        
        int i = pr.second, j = pos[i];
        if (pr.first>x.len) {
            printf("-1\n");
            return 0;
        }
        if (pos[i]+1<t.size())
            st.insert({max(t[i].len, t[++pos[i]].len), i});

        ans[x.index] = {i+1, j+1};
    }

    for (int i=1; i<=m; ++i) 
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}