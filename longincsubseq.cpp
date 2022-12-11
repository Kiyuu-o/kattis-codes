#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

int n;
int L[MAX_N], L_id[MAX_N], P[MAX_N];
int A[MAX_N];

void reconstruct_print(int end, int a[], int p[]) {
	int x = end;
	stack<int> s;
	for (; x >= 0; x = p[x]) s.push(x);
	while (s.size() > 0) {
		cout << s.top() << " \n"[s.size() == 1]; s.pop();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		memset(A, 0, sizeof(A));
		memset(L, 0, sizeof(L));
		memset(L_id, 0, sizeof(L_id));
		memset(P, 0, sizeof(P));

		for (int i = 0; i < n; ++i) cin >> A[i];

		int lis = 0, lis_end = 0;
		for (int i = 0; i < n; ++i) {
			int pos = lower_bound(L, L+lis, A[i]) - L;
			L[pos] = A[i];
			L_id[pos] = i;
			P[i] = pos ? L_id[pos - 1] : -1;
			if (pos + 1 > lis) {
				lis = pos + 1;
				lis_end = i;
			}
		}
		cout << lis << '\n';
		reconstruct_print(lis_end, A, P);
	}
	return 0;
}
