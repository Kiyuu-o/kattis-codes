// Author:	Kexuan Miao
// Time:	2022/11/18 23:03:32
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;

	vector<vi> adj(n);
	vi color(n, INF);
	vii edges;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges.push_back({u, v});
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int s = 0;
	queue<int> q;
	q.push(s);
	color[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto& v : adj[u])
			if (color[v] == INF) {
				color[v] = 1-color[u];
				q.push(v);
			}
	}
	
	for (auto &[u, v] : edges) {
		cout << color[u] << '\n';
	}

	return 0;
}
