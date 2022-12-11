#include <bits/stdc++.h>
using namespace std;

const int maxn = 100050;

int n, p;
int x[maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> p;

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		x[i] -= p;
	}
	
	int sum = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		sum += x[i];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	cout << ans << "\n";
	return 0;
}
