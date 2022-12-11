#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using iii = tuple<int, int, int>;

bool flag = true;
vi uf;

void build_uf() {
	int n = sz(uf);
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
	int n, m;
	cin >> n >> m;
	
	if (n == 0 && m == 0) {flag = false; return;}

	uf.assign(n, 0);
	build_uf();
	
	// using a tuple to create an edge list here
	vector<iii> EL(m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u > v) swap(u, v);
		EL[i] = {w, u, v};
	}
	sort(all(EL));
	
	vector<pii> ans;
	int mst_cost = 0, num_taken = 0;
	for (int i = 0; i < m; ++i) {
		auto [w, u, v] = EL[i];
		if (find(u) == find(v)) continue;
		mst_cost += w;
		ans.push_back({u, v});
		merge(u, v);
		++num_taken;
		if (num_taken == n-1) break;
	}
	sort(all(ans));
	
	// if num_taken is not v-1, then this is not a MST yet.
	if (num_taken != n-1) {
		cout << "Impossible\n";
		return;
	}

	cout << mst_cost << "\n";
	for (auto [u, v] : ans)
		cout << u << ' ' << v << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	while (flag)
		solve();
}
