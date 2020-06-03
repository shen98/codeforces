#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 31;
ll c[35];
int n, q;
long long ans = 0x3f3f3f3f3f3f3f3f, cur;

int main() {
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> c[i];
        if(i) c[i] = min(2 * c[i - 1], c[i]);
    }
    for(int i = n; i <= N; ++i) c[i] = c[i - 1] * 2;

    for(ll x = q; x <= (1ll << 31ll); x += x & (-x)) {
        ll s = 0;
        for(int i = 0; i <= 31; ++i) {
            if(x & (1ll << (ll)i)) s += c[i];
        }
        ans = min(ans, s);
    }

    cout << ans << endl;
    return 0;
}
