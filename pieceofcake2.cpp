#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h, v;
	cin >> n >> h >> v;
	int area = 4 * max(h, n-h) * max(n-v, v);
	cout << area << '\n';
	return 0;
}
