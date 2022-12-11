#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	
	set<int> st;
	map<int, int> mp;
	// k+1 special case
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x < k) {
			st.insert(x);
			mp[x]++;
		}
		else {
			mp[k]++;
		}
	}
	
	int cnt = 0;
	int ans = 0;
	while (true) {
		cnt = 0;
		vector<int> v1;

		for (auto d : st) {
			while (mp[d] > 0 && d >= cnt+1) {
				cnt++;
				mp[d]--;
				if (cnt == k) break;
			}
			if (cnt == k) break;
			if (mp[d] == 0) v1.push_back(d);
		}

		for (auto x : v1) {
			st.erase(x);
		}
		v1.clear();

		if (cnt == k) {
			ans++;
			continue;
		}
		if (cnt + mp[k] < k) break;
		
		mp[k] -= (k-cnt);
		ans++;
	}
	cout << ans << "\n";
}

int main() {
	solve();
}