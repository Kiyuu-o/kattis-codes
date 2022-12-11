#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using pd = pair<double, double>;
using dii = tuple<double, int, int>;

vi uf;

void build_uf() {
	// initialize the union-find set
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

double dist(const pd& a, const pd& b) {
	return sqrt(pow(a.first-b.first, 2.0) + pow(a.second-b.second, 2.0));
}

void solve() {
	int m;
	cin >> m;
	
	uf.assign(m, 0);
	build_uf();

	vector<pd> v1;
	for (int i = 0; i < m; ++i) {
		double x, y;
		cin >> x >> y;
		v1.push_back({x, y});
	}

	vector<dii> EL;
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			EL.push_back({dist(v1[i], v1[j]), i, j});
		}
	}
	sort(all(EL));

	int num_taken = 0;
	double mst_cost = 0.0;
	for (int i = 0; i < (int) EL.size(); ++i) {
		auto [w, u, v] = EL[i];
		if (find(u) == find(v)) continue;
		mst_cost += w;
		merge(u, v);
		++num_taken;
		if (num_taken == m-1) break;
	}
	cout.precision(10);
	cout << mst_cost << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	while (n--) {
		solve();
	}
	return 0;
}
