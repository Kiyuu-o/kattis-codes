#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;

// union-find set
vi uf;
/*
 * Kruskal's Algorihtm used in solution
 * O(E Log(V))
 */

void build_uf() {
	int n = (int) uf.size();
	for (int i = 0; i < n; ++i)
		uf[i] = i;
}

int find(int u) {
	if (uf[u] != u) uf[u] = find(uf[u]);
	return uf[u];
}

void merge(int u, int v) {
	int pu = find(u), pv = find(v);
	if (pu == pv) return;
	uf[pu] = pv;
}

void solve() {
	int n;
	cin >> n;

	uf.assign(n, 0);
	build_uf();

	vector<iii> EL;
	for (int u = 0; u < n; ++u) {
		for (int v = 0; v < n; ++v) {
			int w;
			cin >> w;
			if (u >= v) continue;
			EL.push_back({w, u, v});
		}
	}
	sort(all(EL));

	int num_taken = 0;
	vector<pii> ans;
	for (int i = 0; i < EL.size(); ++i) {
		auto [w, u, v] = EL[i];
		if (find(u) == find(v)) continue;	// same set already
		merge(u, v);
		++num_taken;
		ans.push_back({u, v});
		if (num_taken == n-1) break;	// n-1 edges in MST
	}

	sort(all(ans));
	for (auto [u, v] : ans)
		cout << u + 1 << ' ' << v + 1 << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
