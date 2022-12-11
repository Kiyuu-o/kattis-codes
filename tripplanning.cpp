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

	int n, m;
	cin >> n >> m;
	//if (m < n) {
		//cout << "impossible\n";
		//return 0;
	//}

	vi edges(n + 1, -1);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u+1 == v) {
			edges[u] = i;
		}
		if (u == 1 && v == n) {
			edges[n] = i;
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (edges[i] == -1) {
			cout << "impossible\n";
			return 0;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << edges[i] << "\n";
	}
	return 0;
}
