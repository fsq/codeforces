#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#define cind(x) scanf("%d", &x)
using namespace std;

int encode(int h, int m) {
    return h*60 + m;
}

string decode(int t) {
    if (t<0) t += 24*60;

    int h = t/60;
    int m = t%60;

    return to_string(h) + to_string(m);
}

int main() {
    int x;
    int h, m;
    cind(x);
    cind(h), cind(m);

    int t = encode(h, m);
    int i=0;
    while (true) {
        string s = decode(t - i*x);
        // cout << s << endl;
        if (s.find('7')!=string::npos)
            break;
        ++i;
    }

    printf("%d\n", i);


    return 0;
}