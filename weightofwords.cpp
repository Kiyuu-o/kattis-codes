#include <bits/stdc++.h>
using namespace std;

int main() {
	string alpha = " abcdefghijklmnopqrstuvwxyz";
	int l, w;
	cin >> l >> w;
	if (w > 26*l || w < l) cout << "impossible\n";
	else {
		int average = w / l;
		for (int i = 1; i <= l; i++) {
			cout << alpha[average];
			w -= average;
			if (i != l) average = w / (l - i);
		}
		cout << '\n';
	}
	return 0;
}
