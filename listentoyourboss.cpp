#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class SparseTable {                              // OOP style
private:
  vi A, P2, L2;
  vector<vi> SpT;                                // the Sparse Table
public:
  SparseTable() {}                               // default constructor

  SparseTable(vi &initialA) {                    // pre-processing routine
    A = initialA;
    int n = (int)A.size();
    int L2_n = (int)log2(n)+1;
    P2.assign(L2_n, 0);
    L2.assign(1<<L2_n, 0);
    for (int i = 0; i <= L2_n; ++i) {
      P2[i] = (1<<i);                            // to speed up 2^i
      L2[(1<<i)] = i;                            // to speed up log_2(i)
    }
    for (int i = 2; i < P2[L2_n]; ++i)
      if (L2[i] == 0)
        L2[i] = L2[i-1];                         // to fill in the blanks

    // the initialization phase
    SpT = vector<vi>(L2[n]+1, vi(n));
    for (int j = 0; j < n; ++j)
      SpT[0][j] = j;                             // RMQ of sub array [j..j]

    // the two nested loops below have overall time complexity = O(n log n)
    for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
      for (int j = 0; j+P2[i]-1 < n; ++j) {      // for all valid j
        int x = SpT[i-1][j];                     // [j..j+2^(i-1)-1]
        int y = SpT[i-1][j+P2[i-1]];             // [j+2^(i-1)..j+2^i-1]
        SpT[i][j] = A[x] <= A[y] ? x : y;
      }
  }

  int RMQ(int i, int j) {
    int k = L2[j-i+1];                           // 2^k <= (j-i+1)
    int x = SpT[k][i];                           // covers [i..i+2^k-1]
    int y = SpT[k][j-P2[k]+1];                   // covers [j-2^k+1..j]
    return A[x] <= A[y] ? x : y;
  }
};

const int MAXN = 1e5+5;

int L[2*MAXN], E[2*MAXN], H[MAXN], idx;
vector<vi> children;
vi v1;

void dfs(int cur, int depth) {
	H[cur] = idx;
	E[idx] = cur;
	idx++;
	v1.push_back(depth);
	for (auto &nxt : children[cur]) {
		dfs(nxt, depth+1);
		E[idx] = cur;		// backtrack to cur.
		idx++;
		v1.push_back(depth);
	}
}

void buildRMQ() {
	idx = 0; memset(H, -1, sizeof(H));
	dfs(0, 0);	// root is at index 0.
}

void solve() {
	int N, m;
	cin >> N >> m;
	
	children = vector<vi>(N);
	// decrease all index by 1.
	// 1 to 0, 2 to 1...
	for (int i = 2; i <= N; ++i) {
		int x;
		cin >> x;
		children[x-1].push_back(i-1);
	}

	v1 = vector<int>(0);
	buildRMQ();
	SparseTable SpT(v1);
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		bool flag = false;
		// the index of first occurance of a-1 < index of first occurance of b-1.
		if (H[a-1] < H[b-1]) {
			cout << "Yes\n";
			continue;
		}
		int res = E[SpT.RMQ(H[b-1], H[a-1])];
		if (res == b-1) cout << "No\n";
		else cout << "Yes\n";
	}

}

int main() {
	solve();
	return 0;
}
