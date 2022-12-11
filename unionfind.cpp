#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
using vi = vector<int>;

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
	int n, q;
	cin >> n >> q;

	uf.assign(n, 0);
	build_uf();

	for (int i = 0; i < q; ++i) {
		int a, b;
		char query;
		cin >> query >> a >> b;
		if (query == '=') merge(a, b);
		else if (find(a) == find(b)) cout << "yes\n";
		else cout << "no\n";
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
