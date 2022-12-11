/*
 * Each state:
 * possible: c + u > f
 * impossible: c + u <= f
 *
 * minimize the cost
 *
 * for each state, calculate the cost and weight
 * do a knapsack dp on all states.
 */
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int inf = 0x3f3f3f3f;

int memo[3000][5000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int s, total = 0;
	cin >> s;
	vi d(s), c(s), f(s), u(s);
	memset(memo, 0x3f, sizeof(memo));
	for (int i = 0; i < s; i++) {
		cin >> d[i] >> c[i] >> f[i] >> u[i];
		total += d[i];
	}
	vi w(s, 0);
	for (int i = 0; i < s; i++) {
		if (c[i] + u[i] <= f[i]) {	// impossible
			d[i] = 0;
			continue;
		}
		if (f[i] - c[i] + u[i] >= 0) w[i] = (f[i]-c[i]+u[i]) / 2 + 1;
	}
	// memo[state][delegate]
	memo[0][d[0]] = w[0]; memo[0][0] = 0;
	for (int i = 1; i < s; i++)
		for (int j = 0; j <= total; j++) {
			if (memo[i-1][j] != inf) {
				memo[i][j+d[i]] = min(memo[i][j+d[i]], memo[i-1][j] + w[i]);
				memo[i][j] = min(memo[i][j], memo[i-1][j]);
			}
		}
	int ans = inf;
	for (int vote = total / 2 + 1; vote <= total; vote++) {
		ans = min(ans, memo[s-1][vote]);
	}
	if (ans == inf) cout << "impossible\n";
	else cout << ans << '\n';
	return 0;
}
