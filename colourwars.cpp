// Author:	Kexuan Miao
// Time:	2022/11/19 16:07:15
#include <bits/stdc++.h>
using namespace std;

int o[10005];
int ans;

int main() {
	int n, x;
	cin >> n;
	set<int> s;

	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
		o[x]++;
	}

	for (int i : s) {
		ans += (o[i] + i)/(i+1) * (i+1);
	}

	cout << ans << '\n';
	return 0;
}
