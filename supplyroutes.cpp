#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using iii = tuple<int, int, int>;
using vi = vector<int>;

vi par;

void build_union_find_set(int n) {
	par.resize(n);
	for (int i = 0; i < n; i++) {
		par[i] = i;
	}
}

int find(int u) {
	if (par[u] != u) par[u] = find(par[u]);
	return par[u];
}

void merge(int u, int v) {
	int pu = find(u), pv = find(v);
	if (pu == pv) return;	// same set
	par[pu] = pv;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	build_union_find_set(n);

	set<pii> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.insert({u, v});
	}
	
	vector<iii> query(q);	
	for (int i = 0; i < q; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		query[i] = {t, u, v};
		if (t == 0) edges.erase({u, v});
	}
	
	for (auto &[u, v] : edges) {
		merge(u, v);
	}

	vector<int> ans;
	for (int i = q-1; i >= 0; i--) {
		auto [t, u, v] = query[i];
		if (t == 0) {
			edges.insert({u, v});
			merge(u, v);
		} else {
			if (find(u) == find(v)) ans.push_back(1);
			else ans.push_back(0);
		}
	}
	reverse(begin(ans), end(ans));
	for (int &i : ans) {
		if (i) cout << "safe\n";
		else cout << "unsafe\n";
	}
	return 0;
}
