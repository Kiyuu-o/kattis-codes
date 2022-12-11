#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

int factorial(int x) {
	int res = 1;
	for (int i = 2; i <= x; i++) {
		res *= i;
	}
	return res;
}

int nCr(int n, int r) {
	int res = factorial(n) / factorial(n-r) / factorial(r);
	return res;
}

void solve() {
	int r, s, x, y, w;
	cin >> r >> s >> x >> y >> w;
	double res = 0.0;
	double prob = 1.0*(s-r+1)/s;
	for (int i = x; i <= y; i++) {
		res += 1.0*nCr(y, i) * pow(prob, i)*pow(1.0-prob, y-i);
	}
	res *= w;
	if (res - 1.0 > eps) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) solve();
	return 0;
}
