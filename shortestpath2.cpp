#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9+5;
bool cont = true;
int tc;

struct edge{
	int v, t, p, w;
};

void solve() {
	int n, m, q, s;
	cin >> n >> m >> q >> s;
	if (n == 0 && m == 0 && q == 0 && s == 0) {
		cont = false;
		return;
	}

	vector<vector<edge>> AL(n);
	for (int i = 0; i < m; ++i) {
		int u, v, t, p, w;
		cin >> u >> v >> t >> p >> w;
		AL[u].push_back({v, t, p, w});
	}

	vi dist(n, INF);
	dist[s] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});

	while (pq.size() > 0) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto [v, t, p, w] : AL[u]) {
			int need = 0;
			if (dist[u] > t) {
				if (p == 0) continue;
				need = (dist[u] - t) % p;
				if (need != 0) need = p - need;
			} else if (dist[u] < t) {
				need = t - dist[u];
			}
			if (dist[u] + need + w >= dist[v]) continue;
			dist[v] = dist[u] + need + w;
			pq.push({dist[v], v});
		}
	}
	
	if (tc > 0) cout << "\n";
	tc++;
	for (int i = 0; i < q; ++i) {
		int u;
		cin >> u;
		if (dist[u] == INF) cout << "Impossible\n";
		else cout << dist[u] << "\n";
	}
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	while (cont)
		solve();
}
