#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int t, n;
int a[N], dp[N], f[2 * N];
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i <= n * 2; ++i) f[i] = -1;
        int s = n;
        f[s] = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            if(a[i] == 1) s++; else s--;
            f[s] = i;
        }
        for(int i = n + 1; i <= 2 * n; ++i) cin >> a[i];
        int ans = n * 2 - f[n]; s = n;
        for(int i = 2 * n; i >= n + 1; --i) {
            if(a[i] == 1) s--; else s++;
            if(f[s] == -1) continue;
            //cout << f[s] << " " << s << " " << i << endl;
            ans = min(ans, i - f[s] - 1);
        }
        cout << ans << endl;
    }
}

