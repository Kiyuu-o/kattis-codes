#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct edge {
	int v, w;	// to vertice v, weight w.
};

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto& r : grid)
		for (auto& c : r)
			cin >> c;

	// graph[u]: all edges starting from u.
	vector<vector<edge>> graph(n*n+2);
	int start = n*n, goal = n*n+1;

	for (int ir = 0; ir < n; ++ir) {
		for (int ic = 0; ic < n; ++ic) {
			if (grid[ir][ic] == 1) graph[start].push_back({ir*n+ic, 0});
			if (grid[ir][ic] == k) graph[ir*n+ic].push_back({goal, 0});
			for (int jr = 0; jr < n; ++jr)
				for (int jc = 0; jc < n; ++jc)
					if (grid[ir][ic] + 1 == grid[jr][jc])
						graph[ir*n+ic].push_back({jr*n+jc, abs(ir-jr)+abs(ic-jc)});
		}
	}

	// thus, the top is the smallest element.
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> dist(n*n+2, -1);

	pq.push({0, start});

	while (pq.size() > 0) {
		pii cur = pq.top();
		pq.pop();

		auto [d, u] = cur;
		//int d = cur.first;
		//int u = cur.second;
		
		if (dist[u] != -1) continue;

		dist[u] = d;

		for (edge e : graph[u])
			pq.push({e.w + d, e.v});
	}

	cout << dist[goal] << "\n";
	return 0;
}
