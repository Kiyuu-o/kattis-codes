#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int n, s, m;
	cin >> n >> s >> m;

	vi v(n);
	vector<bool> vis(n, false);
	for (auto& x : v) {
		cin >> x;
	}

	int ind = s - 1;
	int cnt = 0;
	bool trap = false;
	while (true) {
		if (ind < 0) break;
		if (ind >= n) break;
		if (v[ind] == m) break;
		if (vis[ind]) {
			trap = true;
			break;
		}
		vis[ind] = true;
		ind += v[ind];
		cnt++;
	}
	if (v[ind] == m) {
		cout << "magic\n";
	}
	else if (trap) {
		cout << "cycle\n";
	}
	else if (ind < 0) {
		cout << "left\n";
	}
	else {
		cout << "right\n";
	}
	cout << cnt << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
