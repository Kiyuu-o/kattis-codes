#include <bits/stdc++.h>
using namespace std;

int digits(int num) {
	int sum = 0;
	while (num > 0) {
		int res = num % 10;
		sum += res;
		num /= 10;
	}
	return sum;
}

void solve(int n) {
	for (int i = 11; ; i++) {
		if (digits(n) == digits(n*i)) {
			cout << i << endl;
			break;
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		solve(n);
	}
	return 0;
}
