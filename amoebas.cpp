#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 105;

int n, m;
char board[maxn][maxn];
bool vis[maxn][maxn];

void dfs(int row, int col) {
	vis[row][col] = true;

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0) continue;
			int nx = row + i;
			int ny = col + j;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && board[nx][ny] == '#')
				dfs(nx, ny);
		}
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		cin >> board[i];
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == '#' && !vis[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
