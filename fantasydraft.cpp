#include <bits/stdc++.h>
#define trav(a,x) for(auto &a: x)
using namespace std;
using vi = vector<int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	vector<vector<string>> owners(n);
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		for (int j = 0; j < q; j++) {
			string pref;
			cin >> pref;
			owners[i].push_back(pref);
		}
	}

	int p;
	cin >> p;
	vector<string> inp(p);
	trav(x, inp)
		cin >> x;
	map<string, int> mp;
	for (int i = 0; i < p; i++) {
		mp[inp[i]] = i;
	}
	vector<bool> used(p, false);
	vector<vi> v(n);
	for (int i = 0; i < owners.size(); i++) {
		for (int j = 0; j < owners[i].size(); j++) {
			v[i].push_back(mp[owners[i][j]]);
		}
	}

	vi curr(n);
	vector<vi> ans(n);
	int cnt = 0;
	for (int i = 0; i < min(p, n*k); i++) {
		int owner = i % n;
		int &cur = curr[owner];
		while (cur < v[owner].size() && used[v[owner][cur]]) cur++;
		// all pref used up
		if (cur == v[owner].size()) {
			while (used[cnt]) cnt++;
			used[cnt] = true;
			ans[owner].push_back(cnt);
		} else {
			int pref = v[owner][cur];
			used[pref] = true;
			ans[owner].push_back(pref);
		}
	}
	for (int i = 0; i < n; i++) {
		trav(x, ans[i]) {
			cout << inp[x] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
