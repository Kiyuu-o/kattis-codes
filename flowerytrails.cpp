#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using i64 = long long;

const int INF = 0x3f3f3f3f;

struct edge{
	int v, w;
	bool operator<(const edge& rhs) const {return w > rhs.w; }
};

// General Approach: Use dijkstra to find the shortest path
// backtrack from <N-1> and calculate all edges went through
//
// 1st part: apply usual dijkstra
//
// 2nd part: data structure for backtracking the result;
int main() {
	int N, M;
	cin >> N >> M;

	// need map to store the shortest distance from 2 points.
	// use a vector to track the parent node for each later vertice
	map<pii, int> mp;
	vector<vector<int>> par(N);

	// Build a graph using edge
	// to run dijkstra later
	vector<vector<edge>> AL(N);

	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		AL[u].push_back({v, w});
		AL[v].push_back({u, w});

		if (u > v) swap(u, v);
		if (mp[{u, v}] == 0) mp[{u, v}] = INF;
		//if (mp[{v, u}] == 0) mp[{v, u}] = INF;
		mp[{u, v}] = min(mp[{u, v}], w);
		//mp[{v, u}] = min(mp[{v, u}], w);
	}
	
	// Run dijkstra using a priority queue right now.
	// and create a vector storing the minimum distance to each point
	// start forom point 0
	int s = 0;
	vector<int> dist(N, INF); dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});

	while (pq.size() > 0) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto &[v, w] : AL[u]) {
			if (dist[u] + w > dist[v]) continue;

			if (dist[u] + w < dist[v]) {
				par[v].clear();
				dist[v] = dist[u]+w;
				pq.push({dist[v], v});
			}

			if (dist[u] + w == dist[v]) {
				par[v].push_back(u);
			}
		}
	}
	
	// a queue for BFS revisiting all preceeding verticies
	// a bool vector to prevent re-visiting the same point
	i64 ans = 0;
	queue<int> q;
	vector<bool> vis(N, false);
	vis[N-1] = true;
	q.push(N-1);

	// start from the point N-1, backrack to all preceeding points
	// and take the shortest edge b/w u and v.

	while (q.size() > 0) {
		int u = q.front(); q.pop();

		for (auto& v : par[u]) {
			ans += mp[{min(u, v), max(u, v)}];
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}

	cout << ans * 2 << "\n";
	return 0;
}
