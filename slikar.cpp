#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 55;
const int inf = 0x3f3f3f3f;

// so the approach here
// is to first calculate the flooded time for each block
// then run a bfs + checking if the next block can be stepped on

int dist[MAXN][MAXN];
int flood[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
	int r, c;
	cin >> r >> c;
	pii s, t;

	memset(dist, 0x3f, sizeof(dist));
	memset(flood, 0x3f, sizeof(dist));

	vector<string> grid(r);
	queue<pii> q;

	for (auto& st : grid) {
		cin >> st;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'S') s = {i, j};
			if (grid[i][j] == 'D') t = {i, j};
			if (grid[i][j] == '*') {
				flood[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (q.size() > 0) {
		auto [row, col] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int new_r = row + dx[i];
			int new_c = col + dy[i];
			if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c && grid[new_r][new_c] != 'X' && grid[new_r][new_c] != 'D') {
				if (flood[row][col] + 1 < flood[new_r][new_c]) {
					flood[new_r][new_c] = flood[row][col] + 1;
					q.push({new_r, new_c});
				}
			}
		}
	}

	dist[s.first][s.second] = 0;
	q.push(s);
	while (q.size() > 0) {
		auto [row, col] = q.front(); q.pop();
		int d = dist[row][col];
		for (int i = 0; i < 4; i++) {
			int new_r = row + dx[i];
			int new_c = col + dy[i];
			if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c && grid[new_r][new_c] != 'X') {
				if (d + 1 >= flood[new_r][new_c]) continue;
				if (d + 1 < dist[new_r][new_c]) {
					dist[new_r][new_c] = d + 1;
					q.push({new_r, new_c});
				}
			}
		}
	}

	if (dist[t.first][t.second] != inf) {
		cout << dist[t.first][t.second] << '\n';
	} else {
		cout << "KAKTUS\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
