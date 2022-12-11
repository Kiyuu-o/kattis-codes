#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int k;
	cin >> k;

	int ans = 0x3f3f3f3f;
	rep(i, 0, k) {
		int y, c1, c2;
		cin >> y >> c1 >> c2;
		ans = min(ans, y + c1*c2/__gcd(c1,c2));
	}
	cout << ans << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
