#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int maxn = 100050;

int n, ind, f_ind;
bool vis[maxn];
bool used[maxn];
int ans[maxn];

void print(int u, const vector<vi>& DP, const vector<string>& files) {
	used[u] = true;
	for (auto& v : DP[u]) {
		if (!vis[v]) continue;
		if (used[v]) continue;
		print(v, DP, files);
	}
	cout << files[u] << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n;
	cin.ignore();

	string s;
	map<string, int> mp;
	vector<vi> AL(n);
	vector<vi> DP(n);	// dependency
	vector<string> files;

	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		string tmp = "";
		string f;
		for (int j = 0; j < sz(s); ++j) {
			if (s[j] == ':') {
				f = s.substr(0, j);
				if (mp.find(f) == mp.end()) {
					mp[f] = ind++;
					files.push_back(f);
				}
			}
			else if (s[j] == ' ' && sz(tmp) > 0) {
				if (mp.find(tmp) == mp.end()) {
					mp[tmp] = ind++;
					files.push_back(tmp);
				}
				AL[mp[tmp]].push_back(mp[f]);
				DP[mp[f]].push_back(mp[tmp]);
				tmp.clear();
			}
			else if (s[j] != ' ') {
				tmp.push_back(s[j]);
			}
		}
		if (mp.find(tmp) == mp.end()) {
			mp[tmp] = ind++;
			files.push_back(tmp);
		}
		AL[mp[tmp]].push_back(mp[f]);
		DP[mp[f]].push_back(mp[tmp]);
	}


	cin >> s;

	queue<int> q;
	q.push(mp[s]);
	ind = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = true;
		ans[ind] = u;
		ind++;
		for (auto& v : AL[u]) {
			if (vis[v]) continue;
			q.push(v);
			vis[v] = true;
		}
	}
	
	for (int i = 0; i < ind; ++i) {
		if (!used[ans[i]])
			print(ans[i], DP, files);
	}
	return 0;
}
