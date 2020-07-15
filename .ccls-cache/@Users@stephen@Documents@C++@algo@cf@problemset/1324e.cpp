#include <iostream>

using namespace std;

int n, h, l, r, ml, mr;
int dp[2005][2005];

int main() {
    cin >> n >> h >> l >> r;

    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) dp[i][j] = -1e9;
    dp[0][0] = 0;
    int cumsum = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cumsum += a;

        for(int j = 0; j <= i; ++j) {
            int t = (cumsum - j) % h;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (t <= r && t >= l));
            t = (cumsum - j - 1) % h;
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (t <= r && t >= l));
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) ans = max(ans, dp[n][i]);

    cout << ans << endl;
}
