// Author:	Kexuan Miao
// Time:	2022/11/15 10:43:34
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define pb push_back
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int N, M, R;
vii todo[100], range[100];
int ind = 0;
array<int, 3> st;	// use static array to store the starting position

vector<vi> label;
vector<vii> AL;
vi col;
vector<bool> vis;

void ae(pii a, pii b) {	// add edge
	int A = label[a.first][a.second], B = label[b.first][b.second];
	assert(A < sz(AL) && B < sz(AL));
	int len = min(range[a.first][a.second].second, range[b.first][b.second].second)
		-max(range[a.first][a.second].first, range[b.first][b.second].first);
	AL[A].push_back({B, len}), AL[B].push_back({A, len});
}

void dfs(int x, int lo) {
	if (vis[x]) return;
	vis[x] = 1;
	for (auto t : AL[x])
		if (t.second >= lo+st[1])
			dfs(t.first, lo);
}

bool ok(int lo) {
	vis = vector<bool>(sz(AL), 0);
	dfs(ind, lo);
	for (int i = 0; i < sz(vis); i++)
		if (vis[i] && col[i] == N-1)
			return 1;
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int num, len, dist;
		cin >> num >> len >> dist;
		if (i == 0) st = {num, len, dist};
		else todo[num].push_back({dist, len});
	}
	assert(st[0] == 0);
	for (int i = 0; i < N; i++) {
		todo[i].push_back({R, 0});
		sort(all(todo[i]));
		int cur = 0;
		for (auto t : todo[i]) {
			if (cur < t.first) range[i].push_back({cur, t.first});
			cur = t.first + t.second;
		}
	}
	while (ind < sz(range[0]) && range[0][ind].second <= st[2]) ind++;
	int hi = R;
	hi = min(hi, 2*(st[2] - range[0][ind].first));
	hi = min(hi, 2*(range[0][ind].second - st[1] - st[2]));
	assert(hi >= 0);	// hi < 0??
	label.resize(N);
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (auto t : range[i]) {
			label[i].push_back(num++);
			col.push_back(i); vis.emplace_back(); AL.emplace_back();
		}
	}
	// start adding edge..
	for (int i = 0; i < N - 1; i++) {
		int l = 0, r = 0;
		while (l < sz(range[i]) && r < sz(range[i+1])) {
			ae({i,l}, {i+1,r});
			if (range[i][l].second <= range[i+1][r].second) l++;
			else r++;
		}
	}
	if (!ok(0)) {
		cout << "Impossible\n";
		return 0;
	}
	int lo = -1;
	assert(lo <= hi);
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		ok(mid) ? lo = mid : hi = mid - 1;
	}
	cout << fixed << setprecision(1) << lo/2.0 << '\n';
	return 0;
}
