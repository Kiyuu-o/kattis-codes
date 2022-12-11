// Author:	Kexuan Miao
// Time:	2022/11/17 22:26:30
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int n, m;

inline int solve(int start, const vector<vi>& adj, vi deg, const vi& lab) {
	vector<queue<int>> q(2);
	
	for (int i = 0; i < n; i++) {
		if (!deg[i])
			q[lab[i]].push(i);
	}
	
	int curr = start;
	int swap = 0;

	while (!q[0].empty() || !q[1].empty()) {

		while (!q[curr].empty()) {
			int u = q[curr].front(); q[curr].pop();
			for (auto& v: adj[u]) {
				--deg[v];
				if (deg[v] > 0) continue;
				q[lab[v]].push(v);
			}
		}

		curr = 1 - curr;
		++swap;
	}
	return swap - 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vi> adj(n);
		vi lab(n), deg(n);

		for (int i = 0; i < n; i++) {
			cin >> lab[i];
			lab[i]--;
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
			deg[v]++;
		}

		int swap = min(solve(0, adj, deg, lab), solve(1, adj, deg, lab));
		cout << swap << '\n';
	}
	return 0;
}
