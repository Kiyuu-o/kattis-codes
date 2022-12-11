// Author:	Kexuan Miao
// Time:	2022/11/19 16:34:30
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

	string s;
	cin >> s;

	int ind = s.find('a');
	for (int i = ind; i < sz(s); i++)
		cout << s[i];
	cout << '\n';
	return 0;
}
