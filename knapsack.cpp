// Time: 14:44 2022/11/2
// 0-1 Knapsack DP (Bottom-Up)
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;

int C, n;
int V[MAXN], W[MAXN], memo[MAXN][MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> C >> n) {
		memset(memo, 0, sizeof(memo));

		for (int i = 1; i <= n; ++i) {
			cin >> V[i] >> W[i];
		}
		for (int i = 1; i <= n; i++)
			for (int w = 0; w <= C; w++) {
				if (W[i] > w) memo[i][w] = memo[i-1][w];
				else memo[i][w] = max(memo[i-1][w], V[i]+memo[i-1][w-W[i]]);
			}

		int ans = 0, cur = 0;
		for (int w = 0; w <= C; w++) {
			if (memo[n][w] > ans) {
				ans = memo[n-1][w];
				cur = w;
			}
		}
		// backtrack the solution
		stack<int> res;
		for (int i = n; i >= 1; i--) {
			if (memo[i][cur] != memo[i-1][cur]) {
				res.push(i);
				cur -= W[i];
			}
		}
		cout << res.size() << '\n';
		while (res.size() > 0) {
			int x = res.top(); res.pop();
			cout << x-1 << " \n"[res.size() == 0];
		}
	}
	return 0;
}
