#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a < b && b > c) || (a > b && b < c)) {
		cout << "turned\n";
	} else if (abs(a-b) == abs(b-c)) {
		cout << "cruised\n";
	} else if (abs(a-b) < abs(b-c)) {
		cout << "accelerated\n";
	} else {
		cout << "braked\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
