// Author:	Kexuan Miao
// Time:	2022/11/19 16:39:47
#include <bits/stdc++.h>
using namespace std;

int g, t, n, x, ans;

int main() {
	cin >> g >> t >> n;
	int total = (g - t) * 9 / 10;

	for (int i = 0; i < n; i++) {
		cin >> x;
		ans += x;
	}

	cout << total - ans << '\n';
	return 0;
}
