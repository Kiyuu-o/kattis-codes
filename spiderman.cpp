#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
const int inf = 0x3f3f3f3f;

int memo[45][2005];

int main() {
	int N;
	cin >> N;
	while (N--) {
		memset(memo, 0x3f, sizeof(memo));
		map<pii, int> mp;
		int m;
		cin >> m;
		vi dist(m+1);
		for (int i = 1; i <= m; i++) {
			cin >> dist[i];
		}
		memo[0][0] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j <= 1000; j++) {
				if (memo[i-1][j] != inf) {
					int new_d = max(memo[i-1][j], j);
					if (new_d < memo[i][j+dist[i]]) {
						mp[{i,j+dist[i]}] = j;
						memo[i][j+dist[i]] = new_d;
					}
					if (j-dist[i] >= 0 && new_d < memo[i][j-dist[i]]) {
						mp[{i,j-dist[i]}] = j;
						memo[i][j-dist[i]] = new_d;
					}
				}
			}
		}
		if (memo[m][0] == inf) cout << "IMPOSSIBLE\n";
		else {
			vector<char> ans;
			int a = m, b = 0;
			while (a != 0) {
				int last_b = mp[{a, b}];
				if (last_b < b) ans.push_back('U');
				else ans.push_back('D');
				a--;
				b = last_b;
			}
			reverse(ans.begin(), ans.end());
			for (auto c: ans) {
				cout << c;
			}
			cout << '\n';
		}
	}
}
