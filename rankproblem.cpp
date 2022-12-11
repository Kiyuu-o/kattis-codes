#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int n, m;
	cin >> n >> m;
	vi t(n);
	for (int i = 0; i < n; ++i) {
		t[i] = i + 1;
	}

	for (int i = 0; i < m; ++i) {
		int w, l;
		cin >> w >> l;
		int ind1 = t.find(w);
		int ind2 = t.find(l);
		if (ind1 > ind2) {

		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
