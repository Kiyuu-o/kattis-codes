#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const double EPS=1e-9;

void operation(double& width, double& height) {
	double p_w = width;
	double p_h = height;
	width = p_h/2.0;
	height = p_w;
}

void solve() {
	int n;
	cin >> n;
	// start form A_2, go to A_n
	vi v1(1+n);

	for (int i = 2; i <= n; ++i) {
		cin >> v1[i];
	}

	// needed papers to fill the a1.
	int need = 1;
	for (int i = 1; i <= n; ++i) {
		need -= v1[i];
		need *= 2;
		if (need <= 0) break;
	}

	if (need > 0) {
		cout << "impossible\n";
		return;
	}
	
	double width = pow(2.0, -5.0/4.0);
	double height = pow(2.0, -3.0/4.0);
	double ans = height;
	int total = 2;
	for (int i = 2; i <= n; ++i) {
		total -= v1[i];
		if (total > 0) {
			ans += 1.0*total*width;
		} else {
			break;
		}
		operation(width, height);
		total *= 2;
	}
	cout.precision(10);
	cout << ans << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
