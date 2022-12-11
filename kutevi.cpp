#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, t, q;
	int num = 360;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> t;
		num = __gcd(t, num);
	}

	for (int i = 0; i < k; i++) {
		cin >> q;
		if (q % num == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
