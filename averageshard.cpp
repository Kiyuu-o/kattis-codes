// Author:	Kexuan Miao
// Time:	2022/11/24 9:24:37
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

const int EPS = 1e-9;

void solve() {
	int n, m;
	cin >> n >> m;

	vi c(n), e(m);
	for (int &i : c) {
		cin >> i;
	}

	for (int &i : e) {
		cin >> i;
	}

	double average_1 = 0;
	for (int &i : c) {
		average_1 += 1.0*i;
	}
	average_1 /= 1.0*n;

	double average_2 = 0;
	for (int &i : e) {
		average_2 += 1.0*i;
	}
	average_2 /= 1.0*m;
	
	int ans = 0;
	for (int &i : c) {
		if (average_1 - 1.0*i > EPS && 1.0*i - average_2 > EPS)
			ans++;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
