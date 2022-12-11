// Time:	23:01 2022/11/2
// Author: 	Kexuan Miao
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

ll memo[105][30005];
int cost[105];

int n;
map<pii, int> par;

void print_solution(int total) {
	vector<int> res;
	int price = total;
	for (int i = n; i >= 1; i--) {
		if (par[{i, price}] == price) continue;
		int new_p = par[{i, price}];
		int num = (price - new_p) / cost[i];
		while (num--) res.push_back(i);
		price = new_p;
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " \n"[i == res.size()-1];
	}
}

int main() {
	int m, mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	cin >> m;
	vector<int> t(m);
	for (auto& x : t) {
		cin >> x;
		mx = max(mx, x);
	}

	memo[0][0] = 1;	// Initialize the dp-table
	for (int i = 1; i <= n; i++)	// Bottom-Up
		for (int j = 0; j <= mx; j++) {
			if (!memo[i-1][j]) continue;
			int cur = 0;
			while (cur + j <= mx) {
				memo[i][j+cur] += memo[i-1][j];
				par[{i, j+cur}] = j;
				cur += cost[i];
			}
		}
	
	for (auto total : t) {
		if (!memo[n][total]) cout << "Impossible\n";
		else if (memo[n][total] > 1) cout << "Ambiguous\n";
		else print_solution(total);
	}
	return 0;
}
