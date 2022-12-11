// Time: 11:17 2022/11/4
// Author: Kexuan Miao
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main() {
	int n;
	cin >> n;

	vi v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	int ans = 0;
	vi lis(n, 1), lds(n, 1);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (v[i] < v[j]) lds[i] = max(lds[i], lds[j] + 1);
			if (v[i] > v[j]) lis[i] = max(lis[i], lis[j] + 1);
		}
		ans = max(ans, lis[i] + lds[i] - 1);
	}
	cout << ans << '\n';
	return 0;
}
