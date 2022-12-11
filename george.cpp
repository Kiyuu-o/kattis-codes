#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using pii = pair<int, int>;

void solve() {
	int N, M;
	int s, t, K, G;
	cin >> N >> M;
	cin >> s >> t >> K >> G;
	
	vector<int> george(G);
	vector<vector<pii>> AL(N + 1);
	map<pii, pii> mp;	// the time when george start traversing a street, and the w.
	for (int i = 0; i < G; i++) {
		cin >> george[i];
	}
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		// two way streets
		AL[u].push_back({v, w});
		AL[v].push_back({u, w});
	}
	// reconstruct George's route first
	
	int cur = 0;
	for (int i = 1; i < G; ++i) {
		int weight = 0;
		for (auto [v, w] : AL[george[i-1]]) {
			if (v == george[i])
				weight = w;
		}
		mp[{george[i], george[i-1]}] = {cur, weight};
		mp[{george[i-1], george[i]}] = {cur, weight};
		cur += weight;
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(N+1, inf);
	pq.push({K, s});
	dist[s] = K;
	while (pq.size() > 0) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;	// not improving
		for (auto [v, w] : AL[u]) {
			if (mp.find({u, v}) == mp.end()) {
				if (dist[u] + w >= dist[v]) continue;
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			} else {
				int copy_d = d;
				auto [curr, wei] = mp[{u, v}];
				if (d >= curr) copy_d = max(d, curr+wei);
				if (copy_d + w >= dist[v]) continue;
				dist[v] = copy_d + w;
				pq.push({dist[v], v});
			}
		}
	}
	cout << dist[t] - K << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
