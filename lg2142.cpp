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

    string add(const BigNum _b) {
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
};

int main() {
    BigNum a, b;
    a.scan(), b.scan();
    cout << a.minus(b) << endl;
    return 0;
}