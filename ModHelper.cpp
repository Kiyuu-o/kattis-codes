/**
 * Author:		Kexuan Miao
 * Date:		2025-12-30
 * License:		CC0
 * Description:	Common useful helper functions when dealing with mod.
 * Note:		Under the assumption that mod is a prime number.
 * Status:		Not Tested
 */

#pragma once

using ll = long long;
const ll mod = 998'244'353;

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
