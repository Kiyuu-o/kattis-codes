#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int cc;

vector<vi> AL;
vi dfs_num;

void dfs(int u) {
	dfs_num[u] = cc;
	for (auto &v : AL[u]) {
		if (dfs_num[v] == -1)
			dfs(v);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	AL.assign(N+1, vi());
	dfs_num.assign(N+1, -1);
	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		AL[u].push_back(v);
		AL[v].push_back(u);
	}
	// 6 / 2 = 3
	// 7 / 2 = 3
	for (int i = 1; i <= N / 2; i++) {
		if (dfs_num[i] == -1) {
			dfs(i);
			cc++;
		}
	}

	bool fail = false;
	for (int i = 1; i <= N / 2; i++) {
		if (dfs_num[i] != dfs_num[N-i+1]) {
			fail = true;
			break;
		}
	}
	if (fail) cout << "No\n";
	else cout << "Yes\n";
	return 0;
}
