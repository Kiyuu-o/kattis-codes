#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;
// a b c
// a c b
// b c a

// left: plus
// right: share
// swap l, r
// swap second l, r

bool operate(const vector<pii>& x, int& n) {
	//for (auto& [l, r] : x) {
		//cout << l << ' ' << r << "\n";
	//}
	auto [al, ar] = x[0];
	auto [bl, br] = x[1];
	auto [cl, cr] = x[2];
	int dl, dr;
	
	dl = al + bl;
	if (ar != br) return false;
	dr = ar;
	//cout << dl << ' ' << dr << "\n\n";
	if (cl + dl == n && cr == n && dr == n) return true;
	if (cr + dl == n && cl == n && dr == n) return true;
	if (cl + dr == n && cr == n && dl == n) return true;
	if (cr + dr == n && cl == n && dl == n) return true;

	return false;
}

void solve() {
	bool ans = false;
	vector<pii> x;
	for (int i = 0; i < 3; ++i) {
		int h, w;
		cin >> h >> w;
		x.push_back({h, w});
	}
	
	int area = 0;
	for (auto& [h, w] : x) {
		area += h * w;
	}

	// the area is not a perfect square, then impossible.
	if ((int) sqrt(area) * (int) sqrt(area) != area) {
		cout << "NO\n";
		return;
	}

	int n = (int) sqrt(area);
	for (int i = 0; i < 3; ++i) {
		if (operate(x, n)) ans = true;
		swap(x[0].first, x[0].second);
		if (operate(x, n)) ans = true;
		swap(x[1].first, x[1].second);
		if (operate(x, n)) ans = true;
		swap(x[0].first, x[0].second);
		if (operate(x, n)) ans = true;

		if (i == 0) swap(x[1], x[2]);
		else swap(x[0], x[2]);
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
