// Author:	Kexuan Miao
// Time:	2022/11/19 15:20:51
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
	int l, r;
	cin >> l >> r;
	double diag = 1.0* sqrt(2) * l / 2.0;
	if (diag - 1.0*r > EPS)
		cout << "nope\n";
	else
		cout << "fits\n";
	return 0;
}
