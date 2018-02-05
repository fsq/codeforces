#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    long long w, m;
    cin >> w >> m;

    bool valid = false;
    if (w==2)
        valid = true;
    else 
        for (int i=0; i<=100; ++i) 
            if (m==0) {
                valid = true;
                break;
            } else if (m%w==0)
                m /= w;
            else if ((m+1)%w==0)
                m = (m+1) / w;
            else if ((m-1)%w==0)
                m = (m-1) / w;
            else 
                break;
            
    
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}