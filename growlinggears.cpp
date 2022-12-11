#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const double eps = 1e-6;

// highest point is -b/2a
double calc(double a, double b, double c) {
	double hi = -1.0*b/2.0/a;
	return -1.0*a*hi*hi+b*hi+c;
}
void solve() {
	int n;
	double a, b, c;
	cin >> n;
	
	int res = 0;
	double ans;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (i == 0) ans = calc(-a, b, c);
		if (calc(-a, b, c) > ans + eps) {
			ans = calc(-a, b, c);
			res = i;
		}
	}
	cout << res + 1 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc;
	cin >> tc;
	while (tc--)
	solve();
}
