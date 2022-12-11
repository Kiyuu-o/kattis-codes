#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	string s;
	while (getline(cin, s)) {
		vi v;
		int temp = 0;
		for (int i = 0; i < (int) s.length(); ++i) {
			if (s[i] == ' ') {
				v.push_back(temp);
				temp = 0;
			}
			else {
				temp *= 10;
				temp += s[i] - '0';
			}
		}
		v.push_back(temp);
		sort(all(v));
		//for (auto& x : v) {
			//cout << x << ' ';
		//}
		//cout << "\n";
		bool nr = false;
		vector<bool> vis(2001, false);

		for (int i = 0; i < sz(v) - 1; ++i) {
			for (int j = i + 1; j < sz(v); ++j) {
				if (!vis[v[j] - v[i]]) {
					vis[v[j] - v[i]] = true;
				}
				else {
					nr = true;
				}
			}
		}

		if (nr) {
			cout << "not a ruler\n";
		}
		else {
			int n = v[sz(v) - 1];
			bool per = true;
			vi ans;
			for (int i = 1; i <= n; ++i) {
				if (!vis[i]) {
					per = false;
					ans.push_back(i);
				}
			}
			if (per) {
				cout << "perfect\n";
			}
			else {
				cout << "missing";
				for (auto& x : ans) {
					cout << ' ' << x;
				}
				cout << "\n";
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	solve();
}
