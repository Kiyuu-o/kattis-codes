#include <bits/stdc++.h>

const int maxn = 10000050;

int f[maxn];

int main() {
	int N, K;
	std::cin >> N >> K;
	// formula: f(n,k) = (f(n-1,k) + k) % n
	// use <i> for <n> here, <N> indicates the final n
	// base case: f(1,k) = 0
	for (int i = 2; i <= N; ++i) {
		f[i] = (f[i - 1] + K) % i;
		//std::cout << i << ' '<< f[i] << "\n";
	}
	std::cout << f[N] << "\n";
	return 0;
}
