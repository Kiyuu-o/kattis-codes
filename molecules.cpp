// Author:	Kexuan Miao
// Time:	2022/11/22 22:40:47
#include <bits/stdc++.h>
using namespace std;
using pd = pair<double, double>;
using vd = vector<pd>;
using vi = vector<int>;

const int N = 50000;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<pd> point(n, {0, 0});
	vector<bool> known(n, false);
	vector<vi> AL(n, vi());
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x != -1 && y != -1) {
			point[i] = {x, y};
			known[i] = true;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		AL[u].push_back(v);
		AL[v].push_back(u);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < n; j++) {
			if (known[j]) continue;
			pd cur = {0.0, 0.0};
			for (auto &v : AL[j]) {
				cur.first += point[v].first;
				cur.second += point[v].second;
			}
			cur.first /= AL[j].size();
			cur.second /= AL[j].size();

			point[j].first = (point[j].first + cur.first) / 2;
			point[j].second = (point[j].second + cur.second) / 2;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(6) << point[i].first << ' ' << point[i].second << '\n';
	}
	return 0;

}
