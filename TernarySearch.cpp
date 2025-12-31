/**
 * Author:		user kllp on codeforces
 * Date:		2025-12-31
 * License:		CC0
 * Description:	A quick ternary search helper.
 * Note:		The function should be first strictly increasing and then strictly decreasing or vice versa.
 * Source:		https://codeforces.com/blog/entry/11497
 * Status:		Not Tested
 */

using ll = long long;

ll f(ll x) {
    // TODO: implement this as needed
}

ll search(ll lo, ll hi) {
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(f(mid) > f(mid+1)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    return hi;
}
