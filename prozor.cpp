#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 105;

int n, m, k;
char pic[maxn][maxn];
int a[maxn][maxn];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> pic[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (pic[i][j] == '*') a[i][j] = 1;
			if (j > 0) a[i][j] += a[i][j - 1];
		}
	}

	//for (auto &x : a) {
		//for (auto &y : x)
			//cout << y;
		//cout << "\n";
	//}
	
	int ans = 0, mx_i = 0, mx_j = 0;
	for (int i = 0; i <= n - k; ++i) {
		for (int j = 0; j <= m - k; ++j) {
			int cur = 0;
			for (int row = i + 1; row <= i + k - 2; ++row) {
				int r = j + k - 2;
				cur += a[row][r] - a[row][j];
				//cout << a[row][r] << "\n";
				//cout << a[row][j] << "\n";
			}
			//cout << "cur " << cur << "\n";
			if (ans < cur) {
				ans = cur;
				mx_i = i;
				mx_j = j;
			}
		}
	}
	pic[mx_i][mx_j] = '+';
	pic[mx_i+k-1][mx_j] = '+';
	pic[mx_i][mx_j+k-1] = '+';
	pic[mx_i+k-1][mx_j+k-1] = '+';
	for (int j = mx_j+1; j <= mx_j+k-2; ++j) {
		pic[mx_i][j] = '-';
		pic[mx_i+k-1][j] = '-';
	}
	for (int i = mx_i+1; i <= mx_i+k-2; ++i) {
		pic[i][mx_j] = '|';
		pic[i][mx_j+k-1] = '|';
	}
	cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		cout << pic[i] << "\n";
	}
	return 0;
}
