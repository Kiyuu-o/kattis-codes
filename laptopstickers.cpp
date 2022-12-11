#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

int main() {
    int h, l, k;
    cin >> l >> h >> k;

    vector<vi> v1(h, vi(l, -1));

    for (int i = 0; i < k; ++i) {
        int len, hei, x, y;
        cin >> len >> hei >> y >> x;
        for (int j = x; j < min(x + hei, h); ++j) {
            for (int a = y; a < min(y + len, l); ++a) {
                v1[j][a] = i;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < l; ++j) {
            if (v1[i][j] == -1) cout << '_';
            else cout << (char) ('a' + v1[i][j]);
        }
        cout << "\n";
    }
    return 0;
}