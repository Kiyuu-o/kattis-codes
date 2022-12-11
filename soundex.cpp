#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	string s;
	map<char, int> mp;
	mp['B'] = 1;
	mp['F'] = 1;
	mp['P'] = 1;
	mp['V'] = 1;
	mp['C'] = 2;
	mp['G'] = 2;
	mp['J'] = 2;
	mp['K'] = 2;
	mp['Q'] = 2;
	mp['S'] = 2;
	mp['X'] = 2;
	mp['Z'] = 2;
	mp['D'] = 3;
	mp['T'] = 3;
	mp['L'] = 4;
	mp['M'] = 5;
	mp['N'] = 5;
	mp['R'] = 6;
	while (cin >> s) {
		for (int i = 0; i < (int) s.length(); ++i) {
			if (mp.find(s[i]) != mp.end()) {
				if (i > 0 && mp.find(s[i - 1]) != mp.end() && mp[s[i]] == mp[s[i-1]]) {
					continue;
				}
				cout << mp[s[i]];
			}
		}
		cout << "\n";
	}
	return 0;
}
