#include <bits/stdc++.h>
using namespace std;

void solve() {
	string grid, ed, temp;
	map<char, char> revert;
	map<string, int> dist;
	revert['*'] = '.';
	revert['.'] = '*';
	for (int i = 0; i < 3; i++) {
		cin >> temp;
		grid += temp;
	}
	ed = ".........";

	bool found = false;
	dist[grid] = 0;
	queue<string> q;
	q.push(grid);
	while (q.size() > 0) {
		string u = q.front(); q.pop();
		int d = dist[u];
		//cout << u << '\n' << "dist: " << d << '\n';
		for (int i = 0; i < 9; ++i) {
			string new_u = u;
			new_u[i] = revert[new_u[i]];
			if (i-3 >= 0 && i-3 < 9)
				new_u[i-3] = revert[new_u[i-3]];
			if (i+3 >= 0 && i+3 < 9)
				new_u[i+3] = revert[new_u[i+3]];
			if (i%3 > 0)
				new_u[i-1] = revert[new_u[i-1]];
			if (i%3 < 2)
				new_u[i+1] = revert[new_u[i+1]];
			if (dist.find(new_u) == dist.end()) {
				dist[new_u] = d + 1;
				q.push(new_u);
				if (new_u == ed) {
					found = true;
					break;
				}
			}
		}
		if (found) break;
	}
	cout << dist[ed] << '\n';
}

int main() {
	int p;
	cin >> p;
	while (p--) solve();
}
