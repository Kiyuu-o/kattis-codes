#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first > b.first;
}

void solve() {
	int n, t;
	cin >> n >> t;

	vector<int> busy(t);

	vector<pair<int, int> > vii(n);
	for (auto &a: vii) {
		cin >> a.first >> a.second;
	}

	sort(vii.begin(), vii.end(), cmp);

	for (int i = 0; i < n; ++i) {
		int date = vii[i].second;
		while (date >= 0) {
			if (busy[date] == 0) {
				busy[date] = vii[i].first;
				break;
			}
			date--;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < t; ++i) {
		ans += busy[i];
	}

	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
