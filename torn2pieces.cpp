#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

vector<bool> vis;
vector<vi> AL;
vi dfs_parent;
vi ans;
int V;
int st, ed;

void dfs(int u) {
	vis[u] = true;
	if (u == ed) {
		int cur = u;
		while (cur != st) {
			ans.push_back(cur);
			cur = dfs_parent[cur];
		}
		ans.push_back(st);
	}
	for (auto &v: AL[u]) {
		if (!vis[v]) {
			dfs_parent[v] = u;
			dfs(v);
		}
	}
}

int main() {
	int n;
	cin >> n;
	cin.ignore();

	map<string, int> conv;
	vector<string> name;
	AL.assign(5000, vi());
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);

		vector<string> route;
		string cur = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				route.push_back(cur);
				cur = "";
			} else {
				cur.push_back(s[j]);
			}
		}
		route.push_back(cur);
		
		for (auto &station: route) {
			if (conv.find(station) == conv.end()) {
				conv[station] = V;
				name.push_back(station);
				++V;
			}
		}
		int u = conv[route[0]];
		for (int j = 1; j < route.size(); j++) {
			int v = conv[route[j]];
			AL[u].push_back(v);
			AL[v].push_back(u);
		}
	}
	vis.assign(V, false);
	dfs_parent.assign(V, -1);

	string s1, s2;
	cin >> s1 >> s2;
	st = conv[s1];
	ed = conv[s2];

	dfs(st);
	if (vis[ed]) {
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << name[ans[i]] << ' ';
		cout << '\n';
	} else {
		cout << "no route found\n";
	}
	return 0;
}
