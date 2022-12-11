#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9+5;

struct edge{
	int v, w;
};

bool cont = true;
int tc;

void solve() {
	tc++;
	int n, m, q, s;
	cin >> n >> m >> q >> s;
	if (n == 0 && m == 0 && q == 0 && s == 0) {
		cont = false;
		return;
	}

	vector<vector<edge>> AL(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		AL[u].push_back({v, w});
	}

	vi dist(n, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});

	while (pq.size() > 0) {
		auto [d, u] = pq.top(); pq.pop();
		if (dist[u] != -1) continue;
		dist[u] = d;
		for (auto [v, w] : AL[u]) {
			pq.push({w+d, v});
		}
	}

	if (tc > 1) cout << "\n";
	for (int i = 0; i < q; ++i) {
		int u;
		cin >> u;
		if (dist[u] == -1) cout << "Impossible\n";
		else cout << dist[u] << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	while (cont) {
		solve();
	}
}
