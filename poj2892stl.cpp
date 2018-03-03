#include <cstdio>
#include <set>
#include <stack>

using namespace std;

multiset<int> st;
stack<int> stk;

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    char c;
    int p;
    while (m--) {
        scanf("%c", &c);
        if (c=='D') {
            scanf("%d\n", &p);
            st.insert(p);
            stk.push(p);
        } else if (c=='Q') {
            scanf("%d\n", &p);
            if (st.find(p)!=st.end()) {
                printf("0\n");
                continue;
            }
            multiset<int>::iterator it = st.upper_bound(p);
            int max = it==st.end() ? n+1 : *it;
            it = st.lower_bound(p);
            int min = it==st.begin() ? 0 : *(--it);
            printf("%d\n", max-min-1);
        } else {
            scanf("\n");
            p = stk.top();
            stk.pop();
            st.erase(st.find(p));
        }
    }
    return 0;
}