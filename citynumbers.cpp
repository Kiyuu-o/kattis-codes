#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
const int INF = 0x3f3f3f3f;

int n, k;
vector<vi> child, dp;

void dfs(int u, int x, int pu) {
	for (int i = 1; i <= k; i++) {
		if (x == i) continue;
		int sum = i;
		for (int &v : child[u]) {
			if (v == pu) continue;
			dfs(v, i, u);
			sum += dp[v][i];
		}
		dp[u][x] = min(dp[u][x], sum);
	}
}

int main() {
	cin >> n >> k;
	if (k == 1 && n >= 1) {
		cout << -1 << '\n';
		return 0;
	}
	
	dp.assign(n+1, vi(k+1, INF));
	child.assign(n+1, vi());

	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		child[u].push_back(v);
		child[v].push_back(u);
	}

	for (int i = 1; i <= k; i++) {
		dfs(1, i, 0);
	}

	int ans = INF;
	for (int i = 1; i <= k; i++) {
		ans = min(ans, dp[1][i]);
	}
	cout << ans << '\n';
	return 0;
}
