// Author:	Kexuan Miao
// Time:	2022/11/15 14:22:28
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

int N;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> N;
	list<int> q;
	vi v(N), todo(N);
	vector<bool> alive(N, true);
	vector<list<int>::iterator> q_iter(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		todo[i] = i;
		q.pb(i);
		q_iter[i] = prev(q.end());
	}

	vector<vi> ans;
	while (!q.empty()) {
		vi del;
		set<int> next_todo;
		for (int pos : todo) {
			auto iter = q_iter[pos];
			if ((iter != q.begin() && v[*prev(iter)] > v[*iter]) || (next(iter) != q.end() && v[*next(iter)] > v[*iter])) {
				del.pb(pos);
				alive[pos] = false;
				if (iter != q.begin())
					next_todo.insert(*prev(iter));
				if (next(iter) != q.end())
					next_todo.insert(*next(iter));
			}
		}

		if (del.empty())
			break;
		ans.emplace_back();
		for (int pos : del) {
			ans.back().pb(v[pos]);
			q.erase(q_iter[pos]);
		}
		todo.clear();
		for (int pos : next_todo)
			if (alive[pos])
				todo.pb(pos);
	}

	cout << sz(ans) << '\n';
	for (auto row : ans) {
		for (auto i : row)
			cout << i << ' ';
		cout << '\n';
	}
	for (int i : q)
		cout << v[i] << ' ';
	cout << '\n';

	return 0;
}
