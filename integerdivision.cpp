#include <bits/stdc++.h>
using namespace std;
long long ans;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int& x : v)
        cin >> x;
    map<int, int> mp;
    for (int x: v)
        mp[x/d]++;
    for (auto [a,b] : mp)
        ans += 1LL*(b-1)*b/2;
    cout << ans << '\n';
}
