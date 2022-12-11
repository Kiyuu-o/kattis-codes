#include <bits/stdc++.h>
using namespace std;

double memo[105][15];

int main() {
	int k, n;
	while (cin >> k >> n) {
		memset(memo, 0, sizeof(memo));
		for (int num = 0; num <= k; num++) {
			memo[1][num] = 1.0 / (k+1);
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (j > 0) memo[i][j] += 1.0*memo[i-1][j-1];
				memo[i][j] += 1.0*(memo[i-1][j] + memo[i-1][j+1]);
				memo[i][j] /= 1.0*(k+1);
			}
		}
		double ans = 0;
		for (int i = 0; i <= k; i++) {
			ans += 100.0 * memo[n][i];
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}
