#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	bool flag = true;
	int c, p, x, l;
	cin >> c >> p >> x >> l;

	if (x == l) flag = false;

	vector<vi> AL(c + 1);
	vi partner(c + 1);
	vector<bool> vis(c + 1, false);
	for (int i = 0; i < p; ++i) {
		int u, v;
		cin >> u >> v;
		AL[u].push_back(v);
		AL[v].push_back(u);
		partner[u]++;
		partner[v]++;
	}

	queue<int> q;
	q.push(l);
	vis[l] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto &v : AL[u]) {
			--partner[v];
			if (partner[v] > sz(AL[v]) / 2) continue;
			if (vis[v]) continue;
			if (v == x) {
				flag = false;
				break;
			}
			q.push(v);
			vis[v] = true;
		}
		if (!flag) {
			break;
		}
	}
	if (flag) {
		cout << "stay\n";
	}
	else {
		cout << "leave\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	solve();
}
