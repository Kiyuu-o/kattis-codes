#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 100000050;

int n;
vi p;
vi v;

void print_LIS(int i) {
	if (p[i] == -1) {cout << ' ' << v[i]; return;}
	print_LIS(p[i]);
	cout << ' ' << v[i];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	while (cin >> n) {
		if (n == 0) break;
		
		int k = 0, lis_end = 0;
		vi L(n, 0), L_id(n, 0);
		p.assign(n, -1);
		v.assign(n, -1);

		for (auto& x : v) {
			cin >> x;
		}

		for (int i = 0; i < n; ++i) {
			int pos = lower_bound(L.begin(), L.begin()+k, v[i]) - L.begin();
			L[pos] = v[i];
			L_id[pos] = i;
			p[i] = pos ? L_id[pos-1] : -1;
			if (pos == k) {
				k = pos+1;
				lis_end = i;
			}
			else if (pos == k - 1 && v[i] < v[lis_end]) {
				lis_end = i;
			}
		}

		cout << k;
		print_LIS(lis_end);
		cout << "\n";
	}
}
