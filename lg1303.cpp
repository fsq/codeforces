#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace  std;

class BigNum {
private:
    string a;
public:
    BigNum() { }

    void scan() { cin >> a; reverse(a.begin(), a.end()); }

    bool operator >= (const BigNum b) {
        return a.size()==b.a.size() ? a>=b.a : a.size()>=b.a.size();
    }

    string minus(const BigNum b) {
        return  *this >= b ? _minus(b) : "-" + b._minus(*this);
    }

    string _minus(const BigNum _b) const {
        const string& b = _b.a;
        string a = this->a;
        for (int i=0; i<a.size(); ++i) {
            int y = i<b.size() ? b[i] : '0';
            if (a[i]>=y) 
                a[i] = a[i] - y + '0';
            else {
                --a[i+1];
                a[i] = a[i] + 10 - y + '0';
            }
        }
        while (a.size()>1 && a.back()=='0') a.pop_back();
        reverse(a.begin(), a.end());
        return a;
    }

    string add(const BigNum _b) const {
        string ans;
        const string& b = _b.a;
        int carry = 0;
        for (int i=0; i<a.size() || i<b.size() || carry; ++i) {
            int x = i<a.size() ? a[i]-'0' : 0;
            int y = i<b.size() ? b[i]-'0' : 0;
            int s = carry + x + y;
            carry = s / 10; 
            s %= 10;
            ans.push_back(s + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string times(const BigNum _b) const {
        if (is_zero() || _b.is_zero()) return "0";
        const string& b = _b.a;
        vector<int> s(a.size()+b.size());
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<b.size(); ++j)
                s[i+j] += (a[i]-'0') * (b[j]-'0');
        for (int i=0; i+1<s.size(); ++i) {
            s[i+1] += s[i] / 10;
            s[i] %= 10;
        }
        if (s.back()==0) s.pop_back();
        string ans;
        for (int i=s.size()-1; i>=0; --i) ans.push_back(s[i]+'0');
        return ans;
    }

    bool is_zero() const { return a=="0"; }
};

int main() {
    BigNum a, b;
    a.scan(), b.scan();

    cout << a.times(b) << endl;
    return 0;
}