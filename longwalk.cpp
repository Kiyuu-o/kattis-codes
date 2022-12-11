#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define LSOne(S) ((S)&(-S))

ll n, m;

ll get_step(ll x, ll y, map<pll, ll>& mp) {
	ll a = x, b = y;
	if (a == b) return 0;
	if (a > b) swap(a, b);
	if (mp.find({a, b}) != mp.end())	// computed before.
		return mp[{a, b}];
	if (a == 0LL && b != 1LL<<(n-1LL)) {
		mp[{a, b}] = 1LL + get_step(b, 1LL<<(n-1LL), mp);
		return mp[{a, b}];
	} else if (a == 0LL && b == 1LL<<(n-1LL)) {
		mp[{a, b}] = 1LL;
		return 1LL;
	}
	
	ll res = 0;
	ll low_a = LSOne(a), low_b = LSOne(b);
	if (low_a > low_b) {
		ll need = __builtin_ctzll(low_a) - __builtin_ctzll(low_b);
		b = (b << need) % (1LL<<n);
		res += need;
	} else if (low_a < low_b) {
		int need = __builtin_ctzll(low_b) - __builtin_ctzll(low_a);
		a = (a << need) % (1LL<<n);
		res += need;
	}
	
	ll diff = a ^ b;
	if (diff) res += 2LL * (n - __builtin_ctzll(diff));
	mp[{min(x, y), max(x, y)}] = res;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;

	map<pll, ll> mp;
	
	ll a, b;
	ll total = 0;
	cin >> a;
	for (int i = 0; i < m - 1; i++) {
		cin >> b;
		total += get_step(a, b, mp);
		a = b;
	}
	cout << total << '\n';
}
