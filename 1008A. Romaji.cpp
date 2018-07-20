#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isvowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main() {
	string s;
	cin >> s;
	for (int i=0; i<s.size(); ++i)
		if (!isvowel(s[i]) && !(s[i]=='n' || (i+1<s.size() && isvowel(s[i+1])))) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}