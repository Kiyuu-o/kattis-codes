#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
	int n, p;
	cin >> n >> p;

	map<string, string> mp;
	for (int i = 0; i < n; ++i) {
		string input, t;
		cin >> input >> t;
		mp[input] = t;
	}
	
	cin.ignore();
	for (int i = 0; i < p; ++i) {
		string input;
		getline(cin, input);
		//cout << "Wrong" << endl;

		string word = "";
		for (int j = 0; j < sz(input); ++j) {
			if (input[j] == ' ' && j + 1 < sz(input)) {
				word = input.substr(j + 1);
				//cout << word << endl;
			}
		}

		bool flag = true;
		if (input.substr(0, 2) == "nu" && mp[word] != "c")
			flag = false;
		else if (input.substr(0, 2) == "am" && mp[word] != "m")
			flag = false;
		else if (input.substr(0, 5) == "fewes" && mp[word] != "c")
			flag = false;
		else if (input.substr(0, 3) == "lea" && mp[word] != "m")
			flag = false;
		else if (input.substr(0, 5) == "fewer" && mp[word] != "c")
			flag = false;
		else if (input.substr(0, 4) == "less" && mp[word] != "m")
			flag = false;
		else if (input.substr(0, 4) == "many" && mp[word] != "c")
			flag = false;
		else if (input.substr(0, 4) == "much" && mp[word] != "m")
			flag = false;
		else if (input.substr(0, 3) == "few" && mp[word] != "c")
			flag = false;
		else if (input.substr(0, 3) == "lit" && mp[word] != "m")
			flag = false;

		if (flag) {
			cout << "Correct!\n";
		}
		else {
			cout << "Not on my watch!\n";
		}
	}
	

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	solve();
}
