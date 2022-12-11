#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	// Kahn's Algorithm
	priority_queue<int, vi, greater<int>> pq;
	vi lis(N);
	vi in_degree(N+2, 0);
	vi ans;

	for (int i = 0; i < N; ++i) {
		cin >> lis[i];
		in_degree[lis[i]]++;
	}

	for (int u = 1; u <= N; ++u)
		if (in_degree[u] == 0)
			pq.push(u);

	for (int j = 0; j < N; ++j) {
		if (pq.empty()) break;
		int v = lis[j];
		int u = pq.top(); pq.pop();
		ans.push_back(u);
		in_degree[v]--;
		if (in_degree[v] > 0) continue;
		pq.push(v);
	}
	if ((int) pq.size() != 1) {
		cout << "Error\n";
	}
	else {
		for (auto& x : ans) {
			cout << x << "\n";
		}
	}
}
