#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vi p;

void print_LIS(int i) {
	if (p[i] == -1) { printf("%d", A[i]); return; }	// base case
	print_LIS(p[i]);	// backtrack
	printf(" %d", A[i]);
}

int main() {
	int k = 0, lis_end = 0;
	vi L(n, 0), L_id(n, 0);
	p.assign(n, -1);

	for (int i = 0; i < n; ++i) {
		int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
		L[pos] = A[i];
		L_id[pos] = i;
		p[i] = pos ? L_id[pos-1] : -1;
		if (pos == k) {
			k = pos+1;
			lis_end = i;
		}
	}

	printf("Final LIS is of length %d: ", k);
	print_LIS(lis_end); printf("\n");
}
