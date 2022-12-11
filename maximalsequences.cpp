// Author:	Kexuan Miao
// Time:	2022/11/15 22:22:42
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define trav(a,x) for (auto& a: x)
using vi = vector<int>;

vi v;
vector<vi> indexes;

map<int, int> compress(set<int>& s) {
	map<int, int> result;
	int cnt = 0;
	for (auto x: s) {
		result[x] = cnt++;
	}
	return result;
}

bool check(int start, int end, set<int>& query) {
	int total = 0;
	trav(i, query) {
		auto lo = lower_bound(all(indexes[i]), start);
		auto hi = upper_bound(all(indexes[i]), end);
		total += distance(lo, hi);
	}
	return total >= end - start + 1;
}

int solve(int start, set<int>& query) {
	if (!check(start, start, query)){
		return 0;
	}

	int lo = start, hi = sz(v);
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (check(start, mid, query)) lo = mid;
		else hi = mid - 1;
	}
	return lo - start + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	v.resize(n);
	indexes.resize(n);
	trav(x, v) cin >> x;

	set<int> s;
	trav(x, v) {
		s.insert(x);
	}

	map<int, int> mp = compress(s);

	for (int i = 0; i < n; i++) {
		v[i] = mp[v[i]];
		indexes[v[i]].pb(i);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int start, m;
		cin >> start >> m;
		set<int> query;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (mp.count(x) == 0) continue;
			query.insert(mp[x]);
		}
		cout << solve(start - 1, query) << '\n';
	}

	return 0;
}
