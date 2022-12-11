#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void solve() {
	int n, q;
	cin >> n;
	
	vi v1(n);
	for (int i = 0; i < n; ++i) {
		cin >> v1[i];
	}
	cin >> q;

	vi v2 = v1;
	map<int, int> mp;
	sort(v2.begin(), v2.end());
	for (int i = 0; i < n; ++i) {
		mp[v2[i]] = i;
	}
	
	bool sorted = false;
	int t_ind = mp[q];
	for (int i = 0; !sorted; i++) {
		// if this is sorted
		if (v1[t_ind] == q) break;

		if (v1[i] == v2[i]) continue;

		while (v1[i] != v2[i]) {
			int ind = mp[v1[i]];
			swap(v1[i], v1[ind]);
			if (v1[t_ind] == q) {
				sorted = true;
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			cout << v1[i];
		} else {
			cout << ' ' << v1[i];
		}
	}
	cout << "\n";
}

int main() {
	solve();
	return 0;
}
