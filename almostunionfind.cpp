#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
int par[MAXN], setCount[MAXN];
ll setSize[MAXN];

void build_set(int n) {
	for (int i = 1, j = n + 1; i <= n; ++i, ++j) {
		par[i] = j;
		par[j] = j;
		setSize[j] = i;
		setCount[j] = 1;
	}
}

int find (int x) {
	if (par[x] != x) par[x] = find(par[x]);
	return par[x];
}

void merge(int u, int v) {
	int pu = find(u), pv = find(v);
	if (pu == pv) return;	// same set
	par[pu] = pv;
	setSize[pv] += setSize[pu];
	setCount[pv] += setCount[pu];
}

void move(int u, int v) {
	int pu = find(u), pv = find(v);
	if (pu == pv) return;
	par[u] = pv;
	setSize[pu] -= u;
	setSize[pv] += u;
	setCount[pu]--;
	setCount[pv]++;
}

int main() {
	int n, m, command, p, q;
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n >> m) {
		build_set(n);
		for (int i = 0; i < m; ++i) {
			cin >> command;
			if (command == 1) {
				cin >> p >> q;
				merge(p, q);
			} else if (command == 2) {
				cin >> p >> q;
				move(p, q);
			} else {
				cin >> p;
				cout << setCount[find(p)] << ' ' << setSize[find(p)] << "\n";
			}
		}
	}
}
