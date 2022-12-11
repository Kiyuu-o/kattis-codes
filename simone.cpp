// Author:	Kexuan Miao
// Time:	2022/11/19 15:29:15
#include <bits/stdc++.h>
using namespace std;
#define LSOne(S) ((S) & -(S))
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;
	vi color(k + 1);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		color[x]++;
	}

	int mn = INF;
	for (int i = 1; i <= k; i++) {
		mn = min(mn, color[i]);
	}

	vi ans;
	for (int i = 1; i <= k; i++) {
		if (color[i] == mn)
			ans.push_back(i);
	}

	cout << sz(ans) << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';

	return 0;
}
