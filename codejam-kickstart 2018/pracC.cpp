#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void dfs(string s, unordered_map<string, vector<string>>& e, vector<string>& path) {
	while (!e[s].empty()) {
		string nxt = e[s].back();
		e[s].pop_back();
		dfs(nxt, e, path);
	}

	path.push_back(s);
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	for (int n,m,t=1; t<=T; ++t) {
		cout << "Case #" << t << ": ";
		vector<string> path;
		unordered_map<string, vector<string>> e;
		unordered_map<string, int> ind;

		cin >> n;
		{
			string s, t;
			for (int i=0; i<n; ++i) {
				cin >> s >> t;
				e[s].push_back(t);
				++ind[t];
			}
		}

		string src;
		for (const auto& kv : e)
			if (kv.second.size()==ind[kv.first]+1) {
				src = kv.first;
				break;
			}
		if (src.empty()) src = e.begin()->first;

		dfs(src, e, path);
		reverse(path.begin(), path.end());
		for (int i=0; i+1<path.size(); ++i)
			cout << path[i] << "-" << path[i+1] << " ";
		cout << endl;
	}

	return 0;
}