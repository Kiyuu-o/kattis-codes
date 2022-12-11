#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

int main() {
	int N;
	int vac = 0;
	int con = 0;
	string s;
	cin >> N;

	vector<int> v(4, 0), c(4, 0);

	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s[0] == 'Y') {
			vac++;
			for (int j = 1; j < 4; j++) {
				if (s[j] == 'Y') v[j]++;
			}
		} else {
			con++;
			for (int j = 1; j < 4; j++) {
				if (s[j] == 'Y') c[j]++;
			}
		}
	}
	for (int i = 1; i <= 3; i++) {
		double rate_c = 1.0*c[i] / con;
		double rate_v = 1.0*v[i] / vac;
		if (rate_c - rate_v > eps) {
			double res = 100.0*(1.0-rate_v/rate_c);
			printf("%.6lf\n", res);
		} else {
			cout << "Not Effective\n";
		}
	}
	return 0;
}
