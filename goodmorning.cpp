#include <iostream>
using namespace std;

int t, k, ans;

void update(int num) {
	if (abs(num - k) < abs(ans - k))
		ans = num;
}

void backtrack(int num, int key) {
	update(num);
	int res = num;
	for (int i = 0; i < 3; ++i) {
		res = res * 10 + key;
		update(res);
	}
	if (key<=6) {
		if (key%3 != 0) {
			backtrack(num, key+1);
			backtrack(num*10+key, key+1);
		}
		backtrack(num, key+3);
		backtrack(num*10+key, key+3);
	}
	if (key == 7) {
		backtrack(num, key+1);
		backtrack(num*10+key, key+1);
	}
	if (key == 8) {
		backtrack(num, 0);
		backtrack(num*10+key, 0);
		backtrack(num, key+1);
		backtrack(num*10+key, key+1);
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> k;
		ans = 0;
		backtrack(0, 1);
		cout << ans << "\n";
	}
}
