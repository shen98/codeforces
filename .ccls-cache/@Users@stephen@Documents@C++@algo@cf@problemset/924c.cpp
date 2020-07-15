#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int Max = 1, n, d;
ll ans = 0;
int dp[N], a[N];

int main() {
    cin >> n;
    for(int i = 1; i <= n ;++i) {
        cin >> a[i];
        dp[i] = max(a[i] + 1, dp[i - 1]);
    }

    for(int i = n + 1; i >= 1; --i) {
        //dp[i] = max(dp[i], dp[i + 1] - 1);
        if(dp[i] > dp[i - 1] + 1) dp[i - 1]++;
    }

/*    for(int i = 1; i <= n; ++i) cout << dp[i] << " ";*/
    /*cout << endl;*/

    for(int i = 1; i <= n; ++i) {
        ans += dp[i] - a[i] - 1;
    }
    cout << ans << endl;
}
