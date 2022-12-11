// Author:	Kexuan Miao
// Time:	2022/11/23 16:50:58
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int n;

// helper function to convert
// a pair to a single number
int conv(int a, int b) {
	return a*(n+1)+b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;

	vector<vi> AL1, AL2;
	AL1.push_back({0, 0, 0, 0});
	AL2.push_back({0, 0, 0, 0});
	// read the exits for senior
	for (int i = 1; i <= n; i++) {
		vi v(4);
		for (int &j : v) cin >> j;
		AL1.push_back(v);
	}

	// read the exits for me
	for (int i = 1; i <= n; i++) {
		vi v(4);
		for (int &j : v) cin >> j;
		AL2.push_back(v);
	}

	vector<vi> adj((n+1)*(n+1), vi());
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				// bind every pair of i and j
				// i for senior student
				// j for me
				int a1 = AL1[i][k];
				int a2 = AL2[j][k];
				adj[conv(i,j)].push_back(conv(a1, a2));
			}
		}
	}
	
	// run a BFS to generate all
	// paths to the destination
	vector<bool> vis((n+1)*(n+1), false);
	queue<int> q;
	q.push(conv(1,1));
	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (vis[u]) continue;
		vis[u] = true;

		for (int &v : adj[u]) {
			if (!vis[v])
				q.push(v);
		}
	}

	bool work = false;	// senior reaches destination?
	bool fail = false;	// n_senior is bind to any point i_me?
	for (int i = 0; i <= n; i++) {
		// regardless what n binds to 
		// reaching n = working for senior student
		if (vis[conv(n,i)])
			work = true;
	}

	for (int i = 0; i < n; i++) {
		// if n is bind to some none n point in graph 2
		// path will terminate and I will stay in the wrong room
		if (vis[conv(n,i)])
			fail = true;
	}

	if (!work) cout << "Impossible\n";
	else if (fail) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}
