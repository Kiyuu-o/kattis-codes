#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void solve(){
	int l, n;
	cin >> l >> n;
	vi v1(n);
	int mn = -1, mx = -1;

	for (int i = 0; i < n; ++i) {
		cin >> v1[i];
	}

	for (int i = 0; i < n; ++i) {
		mn = max(mn, min(l - v1[i], v1[i]));
		mx = max(mx, max(l - v1[i], v1[i]));
	}
	cout << mn << ' ' << mx << '\n';
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
