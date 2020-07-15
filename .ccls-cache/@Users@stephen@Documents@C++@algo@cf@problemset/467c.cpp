#include <iostream>

using namespace std;
typedef long long ll;

const int N = 5005;
int n, m, k;
ll a[N], s[N];
ll dp[N][N];

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    //memset(dp, 0, sizeof dp);
    for(int i = m; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + s[i] - s[i - m]);
        }
    }

/*    for(int i = 1; i <= k; ++i) {*/
        //for(int j = 1; j <= n; ++j) cout << dp[j][i] << " ";
        //cout << endl;
    /*}*/
    cout << dp[n][k] << endl;
}
