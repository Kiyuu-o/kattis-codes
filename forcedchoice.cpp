#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p, s, cnt, x;
	bool flag = false;
	cin >> n >> p >> s;

	for (int i = 0; i < s; i++) {
		cin >> cnt;
		flag = false;
		for (int j = 0; j < cnt; j++) {
			cin >> x;
			if (x == p) flag = true;
		}
		if (flag) cout << "KEEP\n";
		else cout << "REMOVE\n";
	}
	return 0;
}
