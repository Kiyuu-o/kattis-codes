#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 50;

char d[maxn][maxn][maxn];
int cost[maxn][maxn][maxn];

struct Point {
	int level;
	int row;
	int col;
};

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	int l, r, c;
	while (cin >> l >> r >> c) {
		if (l == 0 && r == 0 && c == 0) break;

		memset(d, 0, sizeof(d));
		memset(cost, -1, sizeof(cost));
		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < r; ++j) {
				cin >> d[i][j];
			}
		}

		Point st;
		Point ed;

		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < r; ++j) {
				for (int k = 0; k < c; ++k) {
					if (d[i][j][k] == 'S') {
						st.level = i;
						st.row = j;
						st.col = k;
					}
					if (d[i][j][k] == 'E') {
						ed.level = i;
						ed.row = j;
						ed.col = k;
					}
				}
			}
		}

		queue<Point> q;
		q.push(st);
		cost[st.level][st.row][st.col] = 0;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();

			for (int i = -1; i <= 1; ++i) {
				if (i == 0) continue;
				int new_l = p.level + i;
				if (new_l >= 0 && new_l < l && cost[new_l][p.row][p.col] == -1 && 
						d[new_l][p.row][p.col] != '#') {
					cost[new_l][p.row][p.col] = cost[p.level][p.row][p.col] + 1;
					Point cur;
					cur.level = new_l;
					cur.row = p.row;
					cur.col = p.col;
					q.push(cur);
				}
			}

			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					if (i!=0 && j!=0) continue;
					if (i == 0 && j == 0) continue;
					int new_r = p.row + i;
					int new_c = p.col + j;
					if (new_r>=0 && new_r<r && new_c>=0 && new_c<c && 
							cost[p.level][new_r][new_c] == -1 && 
							d[p.level][new_r][new_c] != '#') {
						cost[p.level][new_r][new_c] = cost[p.level][p.row][p.col] + 1;
						Point cur;
						cur.level = p.level;
						cur.row = new_r;
						cur.col = new_c;
						q.push(cur);
					}
				}
			}
		}
		int ans = cost[ed.level][ed.row][ed.col];
		if (ans == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << ans << " minutes(s).\n";
		}
	}
	return 0;
}
