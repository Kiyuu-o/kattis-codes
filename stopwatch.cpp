#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t1, t2;
	cin >> n;

	if (n % 2) {
		cout << "still running\n";
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n/2; i++) {
		cin >> t1 >> t2;
		ans += t2 - t1;
	}
	cout << ans << '\n';
	return 0;
}
