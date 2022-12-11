#include <bits/stdc++.h>
using namespace std;
using iii = tuple<double, double, int>;
const double EPS = 1e-8;

int main() {
	int n, cur;
	double A, B, a, b;
	while (cin >> A >> B) {
		vector<iii> v;
		vector<int> ans;
		cur = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({a, b, i});
		}
		sort(v.begin(), v.end());

		bool fail = false;
		double current = 1.0*A, next = 1.0*A;
		for (auto [a, b, i] : v) {
			if (1.0*a - next > EPS) {
				fail = true;
				break;
			}
			if (1.0*a - current > EPS) {
				current = next;
				ans.push_back(cur);
			}
			if (1.0*b - next > EPS) {
				next = b;
				cur = i;
			}
			if (1.0*next - B > EPS || fabs(next - B) <= EPS) {
				current = next;
				ans.push_back(cur);
				break;
			}
		}
		if (1.0*B - current > EPS) fail = true;
		if (fail) {
			cout << "impossible\n";
			continue;
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " \n"[i == ans.size()-1];
		}
	}
	return 0;
}
