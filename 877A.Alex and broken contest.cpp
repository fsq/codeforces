#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<string> names = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string s;
    cin >> s;

    bool shown = false;

    for (auto t : names) {
        auto it = s.find(t);
        if (it==string::npos) continue;
        it = s.find(t, it+1);
        if (it==string::npos) {
            if (shown) {
                printf("NO\n");
                return 0;
            } 
            shown = true;
        } else {
            printf("NO\n");
            return 0;
        }
    }
    if (shown) printf("YES\n");
        else   printf("NO\n");

    return 0;
}