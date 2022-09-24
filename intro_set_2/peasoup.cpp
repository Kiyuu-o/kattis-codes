#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string ans = "";

	while (n--) {
		int k;
		int res[] = {0, 0};
		string name = "";

		cin >> k;
		cin.ignore();
		getline(cin, name);

		for (int i = 0; i < k; ++i) {
			string food;
			getline(cin, food);
			if (food == "pea soup") {
				res[0] = 1;
			}
			else if (food == "pancakes") {
				res[1] = 1;
			}
		}

		if (res[0] == 1 && res[1] == 1 && ans.length() == 0) {
			ans = name;
		}
	}
	if (ans.length() > 0)
		cout << ans << endl;
	else {
		cout << "Anywhere is fine I guess" << endl;
	}
}

int main() {
	solve();
	return 0;
}
