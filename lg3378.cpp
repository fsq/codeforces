#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(1);
    for (int i,x; n; n--) {
        cin >> i;
        if (i==1) {
            cin >> x;
            h.push_back(x);
            for (int i=h.size()-1; i && h[i]<h[i>>1]; i>>=1)
                swap(h[i], h[i>>1]);
        } else if (i==2) 
            cout << h[1] << '\n';
        else {
            swap(h[1], h.back());
            h.pop_back();
            for (int i=1; (i<<1)<h.size(); ) {
                int j = (i<<1|1)<h.size() && h[i<<1|1]<h[i<<1] ? (i<<1|1) : (i<<1);
                if (h[i]>h[j])
                    swap(h[i], h[j]), i = j;
                else
                    break;
            }
        }
    }
    return 0;
}

