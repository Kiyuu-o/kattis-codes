#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	vector<int> army(n+1);
	vector<bool> vis(n+1);
	vector<vector<int>> AL(n+1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		AL[u].push_back(v);
		AL[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		cin >> army[i];
	}

	int cur = army[1];
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 1});
	vis[1] = true;
	while (pq.size() > 0) {
		auto [d, u] = pq.top(); pq.pop();
		if (d >= cur) break;	// smallest army is larger than we can afford.
		cur += d;
		for (auto &v : AL[u]) {
			if (!vis[v]) {
				vis[v] = true;
				pq.push({army[v], v});
			}
		}
	}
	cout << cur << '\n';
	return 0;
}
