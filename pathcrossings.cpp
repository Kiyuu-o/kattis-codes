#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
using pii = pair<int, int>;

struct pt{
	int p, x, y, t;
};

bool operator <(const pt& a, const pt& b) {
	return a.t < b.t;
}

void solve() {
	int P, N;
	cin >> P >> N;

	vector<pt> v1;
	for (int i = 0; i < N; ++i) {
		int p, x, y, t;
		cin >> p >> x >> y >> t;
		v1.push_back({p, x, y, t});
	}
	sort(v1.begin(), v1.end());

	set<pii> st;
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N && v1[j].t - v1[i].t <= 10; ++j) {
			if (v1[i].p == v1[j].p) continue;
			double dist_x = 1.0*v1[i].x - 1.0*v1[j].x;
			double dist_y = 1.0*v1[i].y - 1.0*v1[j].y;
			double dist = sqrt(pow(dist_x,2) + pow(dist_y,2));
			if (1000.0 - dist > EPS || fabs(1000.0-dist) < EPS) {
				st.insert({min(v1[i].p, v1[j].p), max(v1[i].p, v1[j].p)});
			}
		}
	}
	cout << st.size() << "\n";
	for (auto& [p1, p2] : st) {
		cout << p1 << ' ' << p2 << "\n";
	}
}

int main() {
	solve();
}