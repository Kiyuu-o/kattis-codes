#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int n;

vector<int> cal(vector<vi>& e, vi& text) {
	vi ans(n);
	for (int row = 0; row < n; ++row) {
		int res = 0;
		for (int col = 0; col < n; ++col) {
			res += e[row][col] * text[col];
		}
		res %= 37;
		ans[row] = res;
	}
	return ans;
}

void solve() {
	cin >> n;
	vector<vi> e(n);

	string coded = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			e[i].push_back(x);
		}
	}
	string text;
	vi ans;

	cin.ignore();
	getline(cin, text);

	for (int j = 0; j < (sz(text) + n - 1) / n; ++j) {
		vi temp;

		for (int i = 0; i < n; ++i) {
			int ind = j * n + i;
			if (ind >= sz(text)) break; // out of bounds

			if (text[ind] >= 'A' && text[ind] <= 'Z') {
				temp.push_back(text[ind] - 'A');
			}
			else if (text[ind] >= '0' && text[ind] <= '9') {
				temp.push_back(text[ind] - '0' + 26);
			}
			else if (text[ind] == ' ') {
				temp.push_back(36);
			}
		}

		for (int i = 0; i < n - sz(temp); ++i)
			temp.push_back(36);

		vi res = cal(e, temp);

		for (auto& x : res) {
			ans.push_back(x);
		}
	}
	for (auto& x : ans) {
		cout << coded[x];
	}
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();
}
