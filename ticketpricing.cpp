#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 0x3f3f3f3f;

void solve() {
    int N, W;
    cin >> N >> W;

    // dp table
    vector<vector<int>> dp(W+2, vector<int>(N+1, 0));

    // use 1-base indexing, from 1 to W+1.
    vector<vector<pii>> prices(W+2);

    // map<pii, int> par;
    vector<vector<int>> init_p(W+2, vector<int>(N+1, INF));
    for (int i = 1; i <= W+1; ++i) {
        int k;
        cin >> k;

        vi p(k), s(k);
        
        for (int j = 0; j < k; ++j) cin >> p[j];
        for (int j = 0; j < k; ++j) cin >> s[j];

        for (int j = 0; j < k; ++j) {
            prices[i].push_back({p[j], s[j]});
        }
    }

    set<pii> cur;
    set<pii> tmp;
    cur.insert({0, 0});

    for (int i = 1; i <= W + 1; ++i) {
        tmp.clear();
        for (auto [used, revenue] : cur) {
            for (auto [price, sold] : prices[i]) {
                if (used < N) {
                    int increase = min(N-used, sold);
                    int r = revenue + price*increase;

                    if (r > dp[i][used+increase]) {
                        if (i == 1) init_p[i][used+increase] = price;
                        else init_p[i][used+increase] = init_p[i-1][used];
                        dp[i][used+increase] = r;
                    }
                    else if (r == dp[i][used+increase]) {
                        if (i == 1) init_p[i][used+increase] = min(init_p[i][used+increase], price);
                        else init_p[i][used+increase] = min(init_p[i][used+increase], init_p[i-1][used]);
                    }
                }
            }
        }

        for (int j = 1; j < N; ++j) {
            if (dp[i][j])
                tmp.insert({j, dp[i][j]});
        }
        cur = tmp;
    }
    
    int ans = 0;
    int week = 1, seats = 0;

    for (int i = 1; i <= W + 1; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (dp[i][j] > ans) {
                ans = dp[i][j];
                week = i;
                seats = j;
            } else if (dp[i][j] == ans) {
                if (init_p[i][j] < init_p[week][seats]){
                    week = i;
                    seats = j;
                }
            }
        }
    }
    cout << ans << "\n";
    cout << init_p[week][seats] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
