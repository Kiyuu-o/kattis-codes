// Author:	Kexuan Miao
// Time:	2022/11/24 9:34:30
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

void solve() {
	ll n;
	cin >> n;

	ll half = n / 2LL;
	cout << (half+1)*(n-half+1) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	//int t;
	//cin >> t;
	//while (t--) {
		solve();
	//}
	return 0;
}
