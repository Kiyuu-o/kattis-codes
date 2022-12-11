#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 0x3f3f3f3f;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, h, l;
	cin >> n >> h >> l;

	vector<vi> AL(n);
	vi HI(n, INF);
	queue<int> q;

	for (int i = 0; i < h; ++i) {
		int x;
		cin >> x;
		q.push(x);
		HI[x] = 0;
	}

	for (int i = 0; i < l; ++i) {
		int u, v;
		cin >> u >> v;
		AL[u].push_back(v);
		AL[v].push_back(u);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto& v : AL[u]) {
			if (HI[v] != INF) continue;
			HI[v] = HI[u] + 1;
			q.push(v);
		}
	}
	int mx = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (HI[i] > mx) {
			mx = HI[i];
			ans = i;
		}
	}
	cout << ans << "\n";
	return 0;
}
