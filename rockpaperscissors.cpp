#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n, k;

void solve() {
	vi win(n, 0), lose(n, 0);
	map<string, int> mp;
	mp["rock"] = 0;
	mp["scissors"] = 1;
	mp["paper"] = 2;

	int total = k*n*(n-1)/2;
	for (int i = 0; i < total; ++i) {
		int p1, p2;
		string m1, m2;
		cin >> p1 >> m1 >> p2 >> m2;

		if (m1 == m2) continue;	// tie
		else if ((mp[m1]+1)%3 == mp[m2]) {
			// player 1 wins here
			win[p1-1]++;
			lose[p2-1]++;
		} else {
			win[p2-1]++;
			lose[p1-1]++;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (win[i] + lose[i] == 0) cout << "-\n";
		else {
			double res = 1.0 * win[i] / (win[i] + lose[i]);
			printf("%.3lf\n", res);
		}
	}
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc = 0;
	while (true) {
		cin >> n;
		if (n == 0) break;
		cin >> k;
		if (tc > 0) cout << "\n";
		solve();
		tc++;
	}
}
