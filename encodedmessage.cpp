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
	cin >> s;
	string ans = s;
	int len = (int) s.length();
	int n = (int) sqrt(len);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans[(n-1-j)*n+i] = s[i*n+j];
		}
	}
	cout << ans << "\n";
}
// from r, c to n-1-c, r;
// 1, 3 to 3, 3
// original: r*n+c
// now: c*n + n-r-1

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--)
	solve();
}
