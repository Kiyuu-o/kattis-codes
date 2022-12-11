#include <bits/stdc++.h>
using namespace std;

void solve() {
	string cur;
	while (getline(cin, cur)) {
		vector<char> ans;
	vector<char> keys = {'`','1','2','3','4','5','6','7','8','9','0','-','=','Q','W','E','R','T','Y','U','I','O','P','[',']','\\','A','S','D','F','G','H','J','K','L',';', '\'','Z','X','C','V','B','N','M',',','.','/'};

	for (int i = 0; i < (int) cur.length(); ++i) {
		char c = cur[i];
		int ind = -1;
		if (c == ' ') {
			ans.push_back(c);
			continue;
		}
		for (int j = 0; j < (int) keys.size(); j++) {
			if (keys[j] == c) {
				ind = j - 1;
				break;
			}
		}
		if (ind != -1) {
			ans.push_back(keys[ind]);
		}
	}
	for (auto a: ans) {
		cout << a;
	}
	cout << endl;
	}
}
int main() {
	solve();
}
