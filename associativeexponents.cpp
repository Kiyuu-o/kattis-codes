// Author:	Kexuan Miao
// Time:	2022/11/19 16:59:42
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int main() {
	
	string s1 = "What an excellent example!\n", s2 = "Oh look, a squirrel!\n";

	int a, b, c;
	cin >> a >> b >> c;

	if (a == 1)
		cout << s1;
	else if (b == 1)
		if (c == 1)
			cout << s1;
		else
			cout << s2;
	else if (fabs(log(1.0*b*c)/log(1.0*b) - c) < EPS)
		cout << s1;
	else
		cout << s2;
}
