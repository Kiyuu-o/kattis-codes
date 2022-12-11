#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int n, dm;
	cin >> n >> dm;
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int d;
		cin >> d;
		if (d <= dm && ans == -1) {
			ans = i;
		}
	}
	if (ans == -1) cout << "It had never snowed this early!\n";
	else cout << "It hadn't snowed this early in " << ans << " years!\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
