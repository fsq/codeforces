#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class BigNum {
private:
    string a;
public:
    BigNum() { }

    BigNum(string s):a(move(s)) { reverse(a.begin(), a.end()); }

    bool operator < (const BigNum b) const {
        return a.size()==b.a.size() ? gets()<b.gets() : a.size()<b.a.size();
    }

    string times(int b) const {
        if (is_zero() || !b) return "0";
        vector<int> s(a.size()+to_string(b).size());
        for (int i=0; i<a.size(); ++i)
            s[i] = (a[i]-'0') * b;
        for (int i=0; i+1<s.size(); ++i) {
            s[i+1] += s[i] / 10;
            s[i] %= 10;
        }
        if (s.back()==0) s.pop_back();
        string ans;
        for (int i=s.size()-1; i>=0; --i) ans.push_back(s[i]+'0');
        return ans;
    }

    string div(int b) const {
        string ans;
        int s = 0;
        for (int i=a.size()-1; i>=0; --i) {
            s = s * 10 + (a[i]-'0');
            ans.push_back(s / b + '0');
            s = s % b;
        }
        int i = 0;
        while (ans[i]=='0') ++i;
        return i==ans.size() ? "0" : ans.substr(i);
    }

    bool is_zero() const { return a=="0"; }

    string gets() const {
        string s = a; reverse(s.begin(), s.end()); return s;
    }
};

vector<int> a, b;
vector<pair<int, int>> s;

int main() {
    int n;
    cin >> n;
    ++n;
    a.resize(n), b.resize(n), s.resize(n);

    for (int i=0; i<n; ++i) {
        cin >> a[i] >> b[i];
        s[i] = {a[i]*b[i], i};
    }

    sort(s.begin()+1, s.end());

    BigNum sum(to_string(a[0])), ans("0");
    for (int i=1; i<s.size(); ++i) {
        auto t = sum.div(b[s[i].second]);
        if (ans<t) ans = t;
        sum = sum.times(a[s[i].second]);
    }

    cout << ans.gets() << endl;

    return 0;
}