#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

struct Point {
	int l, r, c, v;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int L, R, C;
	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0) break;

		vector<vector<string>> board(L);
		bool vis[L][R][C];
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				string s;
				cin >> s;
				board[i].push_back(s);
			}
		}

		Point st, ed;
		st.v = 0;
		ed.v = -1;
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					if (board[i][j][k] == 'S') {
						st.l = i;
						st.r = j;
						st.c = k;
					}
					else if (board[i][j][k] == 'E') {
						ed.l = i;
						ed.r = j;
						ed.c = k;
					}
				}
			}
		}

		queue<Point> q;
		q.push(st);
		vis[st.l][st.r][st.c] = true;
		bool flag = false;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();

			if (p.l == ed.l && p.r == ed.r && p.c == ed.c) {
				flag = true;
				ed.v = p.v;
				break;
			}

			if (p.l > 0) {
				auto cur = p;
				cur.l--;
				cur.v++;
				if (!vis[cur.l][cur.r][cur.c] && board[cur.l][cur.r][cur.c] != '#') {
					q.push(cur);
					vis[cur.l][cur.r][cur.c] = true;
				}
			}
			if (p.l < L-1) {
				auto cur = p;
				cur.l++;
				cur.v++;
				if (!vis[cur.l][cur.r][cur.c] && board[cur.l][cur.r][cur.c] != '#') {
					q.push(cur);
					vis[cur.l][cur.r][cur.c] = true;
				}
			}

			if (p.r > 0) {
				auto cur = p;
				cur.r--;
				cur.v++;
				if (!vis[cur.l][cur.r][cur.c] && board[cur.l][cur.r][cur.c] != '#') {
					q.push(cur);
					vis[cur.l][cur.r][cur.c] = true;
				}
			}

			if (p.r < R-1) {
				auto cur = p;
				cur.r++;
				cur.v++;
				if (!vis[cur.l][cur.r][cur.c] && board[cur.l][cur.r][cur.c] != '#') {
					q.push(cur);
					vis[cur.l][cur.r][cur.c] = true;
				}
			}

			if (p.c > 0) {
				auto cur = p;
				cur.c--;
				cur.v++;
				if (!vis[cur.l][cur.r][cur.c] && board[cur.l][cur.r][cur.c] != '#') {
					q.push(cur);
					vis[cur.l][cur.r][cur.c] = true;
				}
			}

			if (p.c < C-1) {
				auto cur = p;
				cur.c++;
				cur.v++;
				if (!vis[cur.l][cur.r][cur.c] && board[cur.l][cur.r][cur.c] != '#') {
					q.push(cur);
					vis[cur.l][cur.r][cur.c] = true;
				}
			}
		}
		if (flag) {
			cout << "Escaped in " << ed.v << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
	}
	return 0;
}
