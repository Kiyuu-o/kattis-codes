#include <bits/stdc++.h>
using namespace std;

int cur, ans;

int main() {
	int n, p, d;
	cin >> n >> p >> d;
	string input;
	cin >> input;
	input += input;
	for (int i = n; i > n - p; i--) {
		if (input[i] == 'Z') cur++;
	}
	if (cur < d) ans++;
	for (int i = n + 1; i < 2*n; i++) {
		if (input[i] == 'Z')
			cur++;
		if (input[i - p] == 'Z')
			cur--;
		if (cur < d)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}
