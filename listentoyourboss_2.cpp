#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

const int MAXN = 1e5+10;
const int K = 25;

vector<vector<int>> children;

int L[2*MAXN], E[2*MAXN], H[MAXN], idx;

void dfs(int cur, int depth) {
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  for (auto &nxt : children[cur]) {
    dfs(nxt, depth+1);
    E[idx] = cur;                              // backtrack to current node
    L[idx++] = depth;
	}
}

void buildRMQ() {
  idx = 0;
  memset(H, -1, sizeof H);
  dfs(0, 0);                       // we assume that the root is at index 0
}

int lg[MAXN+1];
int st[MAXN][K + 1];

int RMQ(int l, int r) {
	int j = lg[r - l + 1];
	int minimum = min(st[l][j], st[r - (1 << j) + 1][j]);
	return minimum;
}

void solve() {
	int n, m;
	cin >> n >> m;
	children = vector<vi>(n);
	for (int i = 2; i <= n; ++i) {
		int x;
		cin >> x;
		children[x-1].push_back(i-1);
	}
	buildRMQ();

	// log2 arrays
	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		lg[i] = lg[i/2] + 1;

	// sparse table.
	for (int i = 0; i < idx; i++)
		st[i][0] = L[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= idx; i++)
			st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		bool flag = false;
		cin >> a >> b;

		if (H[a-1] > H[b-1]) {
			flag = true;
			swap(a, b);
		}
		int lca = E[RMQ(H[a-1], H[b-1])];
		if (flag) swap(a, b);

		if (lca == b - 1) cout << "No\n";
		else cout << "Yes\n";
	}
}


int main() {
	solve();
}
