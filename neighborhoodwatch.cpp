#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v;
	v.push_back(1);
	for (int i = 0; i < k; i++) {
		int h;
		cin >> h;
		v.push_back(h);
	}
	v.push_back(n);

	ll total = 1LL*n*(n-1)/2 + k;
	//cout << total << '\n';
	k += 2;

	for (int i = 1; i < k; i++) {
		if (v[i] == v[i-1]) continue;
		int num = v[i] - v[i-1] - 1;
		//cout << num << '\n';
		total -= 1LL * num * (num-1) / 2;
	}
	cout << total << '\n';
	return 0;
}
