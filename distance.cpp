#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;

int s[200005], a[200005];
ll ans;

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i], &a[i]);
    }

    sort(s, s+N);
    sort(a, a+N);

    for (int i = 0; i < N; i++) {
        ans -= 1LL*(N-2*i-1)*s[i]; 
        ans -= 1LL*(N-2*i-1)*a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
