// Author:	Kexuan Miao
// Time:	2022/11/15 22:02:57
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define pb push_back
#define trav(a,x) for (auto& a: x)
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // grid problems

int n1, n2, m1, m2;
int q;

void topo(vector<vi>& adj, vector<vector<bool>>& memo) {
	vi in_degree(sz(adj), 0);
	for (auto u : adj)
		for (auto v : u)
			in_degree[v]++;

	queue<int> q;
	q.push(1);
	memo[1][0] = true;

	while (q.size() > 0) {
		int u = q.front(); q.pop();
		for (auto v : adj[u]) {
			for (int i = 0; i < sz(memo[u]); i++)
				if (memo[u][i])
					memo[v][i+1] = true;
			in_degree[v]--;
			if (!in_degree[v])
				q.push(v);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n1 >> n2 >> m1 >> m2;
	vector<vi> adj1(n1+1), adj2(n2+1);
	vector<vector<bool>> memo1(n1+1, vector<bool>(m1+1, false)), memo2(n2+1, vector<bool>(m2+1, false));
	for (int i = 0; i < m1; i++) {
		int u, v;
		cin >> u >> v;
		adj1[u].pb(v);
	}
	for (int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		adj2[u].pb(v);
	}

	topo(adj1, memo1);
	topo(adj2, memo2);

	unordered_set<int> ans;
	for (int i = 0; i < m1+1; i++) {
		for (int j = 0; j < m2+1; j++) {
			if (memo1[n1][i] && memo2[n2][j])
				ans.insert(i+j);
		}
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		if (ans.count(query) > 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
