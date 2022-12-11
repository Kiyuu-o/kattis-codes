/*
c[i] == g[i] // r++

count[i]

s += min(remaining in c, remaining in g)
*/
#include <iostream>
using namespace std;

const int maxn = 70;

char code[maxn];
char guess[maxn];
int count_1[30];
int count_2[30];

void solve() {
	int n;
	int r = 0;
	int s = 0;
	cin >> n;
	cin >> code >> guess;
	for (int i = 0; i < n; ++i) {
		if (code[i] == guess[i]) r++;
		else {
			count_1[code[i] - 'A']++;
			count_2[guess[i] - 'A']++;
		}
	}
	for (int i = 0; i < 26; ++i) {
		s += min(count_1[i], count_2[i]);
	}
	cout << r << ' ' << s << endl;
}

int main() {
	solve();
	return 0;
}
