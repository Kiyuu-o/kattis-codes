/*
 * keep track of max / min
 * max from 0 to n-2
 * min from n-1 to 1
 */
#include <iostream>
using namespace std;

const int maxn = 100050;

int a[maxn];
int mx[maxn], mn[maxn];

int main() {
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	mx[0] = a[0];
	for (int i = 1; i < n - 1; ++i) {
		mx[i] = max(a[i], mx[i - 1]);
	}
	mn[n-1] = a[n-1];
	for (int i = n - 2; i > 0; --i) {
		mn[i] = min(a[i], mn[i+1]);
	}
	if (a[0] < mn[1])
		ans++;
	if (a[n - 1] > mx[n - 2])
		ans++;
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > mx[i - 1] && a[i] < mn[i + 1])
			ans++;
	}
	cout << ans << endl;
	return 0;
}
