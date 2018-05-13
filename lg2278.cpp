#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Task {
    int id, a, b, p;
    Task(int _id, int _a, int _b, int _p):
        id(_id), a(_a), b(_b), p(_p) {}
};

struct cmp {
    bool operator() (const Task& a, const Task& b) {
        return (a.p > b.p) || (a.p==b.p && a.a<b.a);
    }
};

int main() {
    int id, a, b, p;

    vector<Task> tsk;
    while (scanf("%d %d %d %d", &id, &a, &b, &p)!=EOF) 
        tsk.emplace_back(id, a, b, p);


    reverse(tsk.begin(), tsk.end());
    multiset<Task, cmp> st;
    vector<pair<int,int>> ans;
    int t = 0;
    while (!(st.empty() && tsk.empty())) {
        while (!tsk.empty() && tsk.back().a<=t) {
            st.insert(move(tsk.back()));
            tsk.pop_back();
        }
        if (!st.empty()) {
            auto x = move(*st.begin());
            st.erase(st.begin());
            if (!tsk.empty() && t+x.b>tsk.back().a) {
                x.b -= tsk.back().a - t;
                t = tsk.back().a;
                st.insert(move(x));
            } else {
                ans.emplace_back(x.id, t+=x.b);
            }
        } else 
            t = tsk.back().a;
    }  
    for (auto& t : ans)
        printf("%d %d\n", t.first, t.second);
    return 0;
}