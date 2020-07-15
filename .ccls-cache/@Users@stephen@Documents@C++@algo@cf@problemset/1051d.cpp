#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n, k;
ll dp[2005][2005][5];

int main() {
    cin >> n >> k;
    dp[1][1][0] = dp[1][1][3] = 1;
    dp[1][2][1] = dp[1][2][2] = 1;

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2]+ dp[i-1][j-1][3]) % mod;
            dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j-2][2]+ dp[i-1][j-1][3]) % mod;
            dp[i][j][2] = (dp[i-1][j-1][0] + dp[i-1][j-2][1] + dp[i-1][j][2]+ dp[i-1][j-1][3]) % mod;
            dp[i][j][3] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2]+ dp[i-1][j][3]) % mod;
        }
    }
    cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % mod << endl;
}
