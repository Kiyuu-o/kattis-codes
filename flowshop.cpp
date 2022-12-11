/*
 * 
 */
#include <iostream>
using namespace std;

const int maxn = 1050;

int n, m;
int t[maxn][maxn];
int p[maxn][maxn];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> p[i][j];
	t[0][0] = p[0][0];
	for (int j = 1; j < m; ++j)
		t[0][j] = p[0][j] + t[0][j - 1];
	for (int i = 1; i < n; ++i)
		t[i][0] = p[i][0] + t[i - 1][0];
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j) {
			t[i][j] = max(t[i][j-1], t[i-1][j]) + p[i][j];
		}
	cout << t[0][m - 1];
	for (int i = 1; i < n; ++i)
		cout << ' ' << t[i][m - 1];
	cout << endl;
	return 0;
}
