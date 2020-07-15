#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1005;
const int mod = 1e9 + 7;
int n;
ll p[N], cnt[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];

    cnt[1] = 2;
    for(ll i = 2; i <= n; ++i) {
        if(p[i] == i + 1) cnt[i] = 1;
        else {
            for(ll j = p[i]; j < i; ++j) cnt[i] = (cnt[i] + cnt[j]) % mod;
            cnt[i] += 2;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = (ans + cnt[i]) % mod;
    }

    cout << ans << endl;
/*    for(int i = 1; i <= n; ++i) cout << cnt[i] << " ";*/
    /*cout << endl;*/
}

