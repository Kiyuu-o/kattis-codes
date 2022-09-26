/*
Author: Alberta Blue
Time: 9:55 2022/9/25
int max: 2147483647
data max: 2 ^ 50 * 1000 = 1.125e+18
use long long for this question
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int c, n, m;
	cin >> c >> n >> m;

	vector<ll> cow(n);
	vector<ll> cnt(n, 1);
	for (int i = 0; i < n; ++i) {
		cin >> cow[i];
	}

	vector<ll> ans(51);
	ans[0] = n;
	for (int day = 1; day <= 50; day++) {
		for (int j = 0; j < n; ++j) {
			cow[j] *= 2;
			if (cow[j] > c) {
				cnt[j] *= 2;
			}
			ans[day] += cnt[j];
		}
	}
	
	for (int i = 0; i < m; ++i) {
		int date;
		cin >> date;
		cout << ans[date] << "\n";
	}
}

int main() {
	solve();
	return 0;
}