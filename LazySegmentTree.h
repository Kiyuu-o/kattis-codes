/**
 * Author: Kexuan Miao
 * Date: 2026-01-02
 * Description: 1-indexed lazy segment tree
 * Can be changed by modifying T
 * Time: O(\log N)
 * Status: tested on CF311D
 */

// modulo operation helpers
const ll mod = 95'542'721;

ll add(ll a, ll b) {
	a += b;
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
	return a;
}

ll mul(ll a, ll b) {
	return (a % mod) * (b % mod) % mod;
}

ll modpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) res = mul(res, a);
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

ll inv(ll a) {
	return modpow(a, mod - 2);
}

vector<ll> a;
const int maxn = 48;

// actual definition of Node and Tree
struct Node {
	ll a[maxn];
	Node operator + (const Node& rhs) const {
		Node ans;
		for (int i = 0; i < maxn; i++) {
			ans.a[i] = add(this->a[i], rhs.a[i]);
		}
		return ans;
	}

	void rotate(int x) {
		Node temp;
		for (int i = 0; i < maxn; i++) {
			temp.a[i] = a[i];
		}
		for (int i = 0; i < maxn; i++) {
			a[i] = temp.a[(i+x) % maxn];
		}
	}
};

struct Tree {
	typedef ll T;
	int n;
	vector<Node> tr;
	vector<ll> lazy;
	Tree (int n_) : n(n_), lazy(4*n), tr(4*n) {}

	void apply(int u, int x) {
		tr[u].rotate(x);
		lazy[u] += x;
	}

	void pushdown(int u) {
		apply(2*u, lazy[u]);
		apply(2*u+1, lazy[u]);
		lazy[u] = 0;
	}

	void build(int u, int l, int r) {
		if (l == r) {
			tr[u].a[0] = a[l] % mod;
			for (int i = 1; i < maxn; i++) {
				tr[u].a[i] = modpow(tr[u].a[i-1], 3);
			}
		} else {
			int m = (l + r) / 2;
			build(2*u, l, m);
			build(2*u+1, m+1, r);
			tr[u] = tr[2*u] + tr[2*u+1];
		}
	}

	void update(int u, int l, int r, int ql, int qr, int x) {
		if (qr < l || ql > r) return;
		if (ql <= l && qr >= r) {
			apply(u, x);
		} else {
			pushdown(u);
			int m = (l + r) / 2;
			update(2 * u, l, m, ql, qr, x);
			update(2*u+1, m+1, r, ql, qr, x);
			tr[u] = tr[2*u] + tr[2*u+1];
		}
	}

	T query(int u, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) return 0;
		if (ql <= l && qr >= r) {
			return tr[u].a[0];
		} else {
			pushdown(u);
			int m = (l + r) / 2;
			return add(query(2 * u, l, m, ql, qr), query(2 * u + 1, m + 1, r, ql, qr));
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	a.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	Tree tree(n);
	tree.build(1, 1, n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			cout << tree.query(1, 1, n, l, r) << '\n';
		} else {
			tree.update(1, 1, n, l, r, 1);
		}
	}
}
