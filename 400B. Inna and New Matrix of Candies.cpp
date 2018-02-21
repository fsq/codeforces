#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    unordered_set<int> st;
    bool valid = true;
    for (int i=0; i<n; ++i) {
        int posg, poss;
        char c;
        for (int j=0; j<m; ++j) {
            cin >> c;
            if (c=='G')
                posg = j;
            else if (c=='S')
                poss = j;
        }
        if (posg > poss) {
            valid = false;
            break;
        } else 
            st.insert(poss - posg);
    }

    if (valid) 
        cout << st.size()-(st.find(0)!=st.end()) << endl;
    else
        cout << -1 << endl;

    return 0;
}