#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve() {
	int n;
	cin >> n;

	int mn = 10002;
	int mx = -1;
	vi v1(10001, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		mn = min(mn, x);
		mx = max(mx, x);
		v1[x]++;
	}
	
	int cur = mn;
	int ans = 0;
	while (mn <= mx) {
		cur = mn;
		while (v1[cur] > 0) {
			v1[cur]--;
			cur++;
		}
		while (v1[mn] == 0) mn++;
		ans++;
	}
	cout << ans << "\n";
}

int main() {
	solve();
}