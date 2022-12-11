#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;
/*
 * 1 L-> 2
 * 2 R-> 5
 */

int main() {
	int h = 0;
	string s;
	//cin >> h >> s;
	getline(cin, s);
	for (int i = 0; i < (int) s.length(); ++i) {
		if (s[i] == ' ') {
			s = s.substr(i+1);
			break;
		}
		h *= 10;
		h += s[i] - '0';
	}
	
	int total = 0, res = 1;
	for (int i = 0; i <= h; ++i) {
		total += res;
		res *= 2;
	}

	int cur = 1;
	for (int i = 0; i < (int) s.length(); ++i) {
		cur *= 2;
		if (s[i] == 'R') cur++;
	}
	cur = total - cur + 1;
	cout << cur << "\n";
	return 0;
}
