#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, t;
	cin >> n >> t;
	vi v(n);
	for (auto& x : v) {
		cin >> x;
	}
	int ans = 0, sum = 0;
	for (auto& x : v) {
		sum += x;
		if (sum <= t) ans++;
	}
	cout << ans << "\n";
	return 0;
}
