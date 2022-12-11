#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e10+5;

struct edge{
	int v;
	ll w;
};

struct point{
	ll d;
	int u, used;
	point(ll dd, int uu, int us) : d(dd), u(uu), used(us) {}
};

bool operator >(const point& x, const point& y) {
	if (x.d != y.d)
		return x.d > y.d;
	if (x.u != y.u)
		return x.u > y.u;
	return x.used > y.used;
}

void solve() {
	int n, m, f, s, t;
	cin >> n >> m >> f >> s >> t;

	// road can be used from both direction with same cost.
	vector<vector<edge>> AL(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		AL[u].push_back({v, w});
		AL[v].push_back({u, w});
	}

	// flight is single direction, only from u to v.
	vector<vector<int>> flight(n);
	for (int i = 0; i < f; ++i) {
		int u, v;
		cin >> u >> v;
		flight[u].push_back(v);
	}
	
	// distance array
	// first dimension: vertex
	// second dimension: 0 -> ticket unused, 1 -> ticket used.
	vector<vector<ll>> dist(n, vector<ll>(2, INF));
	dist[s][0] = 0;
	// priority queue for lazy-deletion Dijkstra.
	// {d, u, used}.
	priority_queue<point, vector<point>, greater<point>> pq;
	pq.push({0, s, 0});

	while (pq.size() > 0) {
		auto [d, u, used] = pq.top(); pq.pop();
		//cout << d << ' ' << u << ' ' << used << "\n";
		if (d > dist[u][used]) continue;

		// not using ticket.
		// i.e. not changing the ticket state.
		for (auto& [v, w] : AL[u]) {
			if (dist[u][used]+w >= dist[v][used]) continue;
			dist[v][used] = dist[u][used]+w;
			pq.push({dist[v][used], v, used});
		}

		// if ticket not used yet
		// we're gonna use it.
		if (used) continue;

		for (auto v : flight[u]) {
			if (dist[u][0] >= dist[v][1]) continue;
			dist[v][1] = dist[u][0];
			pq.push({dist[v][1], v, 1});
		}
	}
	cout << min(dist[t][0], dist[t][1]) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
