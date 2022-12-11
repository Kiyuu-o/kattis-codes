#include <bits/stdc++.h>
using namespace std;

void solve() {
	string line;
	cin >> line;

	stack<char> s;

	for (int i = 0; i < (int) line.length(); ++i) {
		if (line[i] != '<') {
			s.push(line[i]);
		}
		else if (s.size() > 0) {
			s.pop();
		}
	}

	vector<char> ans;

	while (s.size() > 0) {
		char cur = s.top();
		s.pop();
		ans.push_back(cur);
	}
	
	reverse(ans.begin(), ans.end());
	for (auto c: ans) {
		cout << c;
	}
	cout << endl;
}

int main() {
	solve();
}
