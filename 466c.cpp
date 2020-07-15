#include <stdio.h>

typedef long long ll;
const int N = 5e5 + 5;
int n;
int a[N], cnt[N];
ll S[N];

int main() {
    scanf("%d", &n);

    ll t = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        t += a[i];
    }

    if(t % 3 != 0) { printf("0\n"); return 0; }

    for(int i = 1; i <= n; ++i) S[i] = S[i - 1] + a[i];

    ll ans = 0;
    for(int i = n - 1; i >= 1; --i) {
        cnt[i] = cnt[i + 1];
        if(S[i] == t / 3) ans += cnt[i];
        if(S[i] == t / 3 * 2) cnt[i]++;
    }

    printf("%lld", ans);
}
