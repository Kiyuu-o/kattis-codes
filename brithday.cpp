#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

enum { UNVISITED = -1 };

vector<vi> AL;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
bool found;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (auto &v : AL[u]) {
		if (dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if (u == dfsRoot) ++rootChildren;

			articulationPointAndBridge(v);
			// articulation part is skipped
			if (dfs_low[v] > dfs_num[u])	// for bridge
				found = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main() {
	int V, E;
	while (cin >> V >> E) {
		if (V == 0 && E == 0) return 0;

		found = false;
		AL.assign(V, vi());

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			AL[u].push_back(v);
			AL[v].push_back(u);
		}

		dfs_num.assign(V, UNVISITED);
		dfs_low.assign(V, 0);
		dfs_parent.assign(V, -1);

		//articulation_vertex.assign(V, 0);
		dfsNumberCounter = 0;
		for (int u = 0; u < V; u++) {
			if (dfs_num[u] == UNVISITED) {
				dfsRoot = u; rootChildren = 0;
				articulationPointAndBridge(u);
				//articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		if (found)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
