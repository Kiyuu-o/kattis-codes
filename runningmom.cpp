#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

enum { UNVISITED = -1, EXPLORED = -2, VISITED = -3 };           // three flags

vector<vi> AL;
vi dfs_num; 
vi dfs_parent;                                   // back vs bidirectional
set<int> cycle;

bool dfs(int u) {
	if (cycle.count(u) > 0) return true;
	for (auto &v : AL[u]) {
		if (dfs(v))
			return true;
	}
	return false;
}

void cycleCheck(int u) {                         // check edge properties
	dfs_num[u] = EXPLORED;                         // color u as EXPLORED
	for (auto &v : AL[u]) {                   // C++17 style, w ignored
		if (dfs_num[v] == UNVISITED) {               // EXPLORED->UNVISITED
			dfs_parent[v] = u;                         // a tree edge u->v
			cycleCheck(v);
		}
		else if (dfs_num[v] == EXPLORED) {           // EXPLORED->EXPLORED
			// Back Edge (Cycle) u->v.
			int cur = u;
			while (cur != v) {
				cycle.insert(cur);
				cur = dfs_parent[cur];
			}
			cycle.insert(v);
		}
	}
	dfs_num[u] = VISITED;                          // color u as VISITED/DONE
}

int main() {
	int n;
	cin >> n;

	int V = 0;
	map<string, int> conv;
	AL.assign(5000, vi());
	for (int i = 0; i < n; i++) {
		string s1, s2;
		int u, v;
		cin >> s1 >> s2;
		
		if (conv.find(s1) == conv.end()) {
			conv[s1] = V;
			++V;
		}
		u = conv[s1];

		if (conv.find(s2) == conv.end()) {
			conv[s2] = V;
			++V;
		}
		v = conv[s2];
		AL[u].push_back(v);
	}

	dfs_num.assign(V, UNVISITED);
	dfs_parent.assign(V, -1);
	for (int i = 0; i < V; i++) {
		if (dfs_num[i] == UNVISITED)
			cycleCheck(i);
	}

	string s1;
	while (cin >> s1) {
		int u = conv[s1];
		if (cycle.count(u) > 0 || dfs(u))
			cout << s1 << " safe\n";
		else
			cout << s1 << " trapped\n";
	}
}
