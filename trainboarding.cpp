#include <bits/stdc++.h>
using namespace std;

int N, L, P, mx, ans, x;

int main() {
	cin >> N >> L >> P;
	
	vector<int> pass(N), car(N);
	for (int i = 0; i < N; i++) {
		car[i] = i * L + L / 2;
	}

	for (int i = 0; i < P; i++) {
		cin >> x;
		int pos = upper_bound(car.begin(), car.end(), x) - car.begin();
		if (pos == car.size()) {
			pass[pos-1]++;
			mx = max(mx, x - car[pos-1]);
		}
		else if (pos == 0 || car[pos] - x <= x - car[pos - 1]) {
			pass[pos]++;
			mx = max(mx, car[pos] - x);
		} else {
			pass[pos-1]++;
			mx = max(mx, x - car[pos-1]);
		}
	}
	
	for (auto num : pass) {
		ans = max(ans, num);
	}
	cout << mx << '\n' << ans << '\n';
	return 0;
}
