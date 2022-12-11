#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n, m;

bool vis[105][105];
char s[105][105];

void dfs(int row, int col) {
	//cout << row << ' ' << col << "\n";
	vis[row][col] = true;
	
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i != 0 && j != 0) continue;
			if (row + i >= 0 && row + i < n && col+j >= 0 && col+j < m 
					&& !vis[row+i][col+j] && s[row+i][col+j] == '-') {
				dfs(row+i, col+j);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	int tc = 1;
	while (cin >> n >> m) {
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!vis[i][j] && s[i][j] == '-') {
					dfs(i, j);
					ans++;
					//cout << ans << "\n";
				}
			}
		}
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
	return 0;
}
