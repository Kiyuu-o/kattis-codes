#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	string bin;
	cin >> n >> d >> bin;
	double k = 0, temp = 0.5, pa = 1.0*d/8;
	for (int i = 2; i < bin.size(); i++) {
		if (bin[i] == '1') k += temp;
		temp /= 2;
	}
	
	vector<char> ans;
	for (int i = 0; i < (1<<n); i++) {
		double a = 0, b = 1.0;
		ans.clear();
		for (int j = 0; j < n; j++) {
			if (i & (1<<j)) {
				b = a + pa*(b-a);
				ans.push_back('A');
			} else {
				a = a + pa*(b-a);
				ans.push_back('B');
			}
		}
		if (a == k) break;
	}
	for (char c : ans)
		cout << c;
	cout << '\n';
}
