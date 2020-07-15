#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
int t, k;
ll cnt[N], S[N];
const ll mod = 1e9 + 7;

int main() {
    scanf("%d %d", &t, &k);

    cnt[0] = 1;
    for(int i = 1; i <= N - 1; ++i) {
        cnt[i] = (cnt[i] + cnt[i - 1]) % mod;
        if(i >= k) cnt[i] = (cnt[i] + cnt[i - k]) % mod;
    }

    for(int i = 1; i <= N - 1; ++i) {
        cnt[i] = (cnt[i] + cnt[i - 1])  % mod;
    }
/*    for(int i = 1; i<= 4; ++i) cout << cnt[i] <<" ";*/
    /*cout << endl;*/
    for(int i = 1; i <= t; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

/*        ll ans = 0, p = 1;*/
        //for(int i = 2; i <= b; ++i) {
            //p = (p + i / k) % mod;
            //if(i >= a) ans  (ans + p) % mod;
        //}
        /*if(a == 1) ans++;*/
        ll ans = cnt[b] - cnt[a - 1];
        if(ans < 0) ans += mod;
        printf("%lld\n", ans);
    }
}
