#include <iostream>

using namespace std;

const int mod = 1e8;
int n1, n2, k1, k2, i, j, k;
int dp[105][105][2];

int main() {
    cin >> n1 >> n2 >> k1 >> k2;

    dp[0][0][0] = dp[0][0][1] = 1;

    for(i = 0; i <= n1; ++i) {
        for(j = 0; j <= n2; ++j) {
            for(k = 1; k <= k1 && k <= i; ++k)
                (dp[i][j][0] += dp[i - k][j][1]) %= mod;
            for(k = 1; k <= k2 && k <= j; ++k)
                (dp[i][j][1] += dp[i][j - k][0]) %= mod;
        }
    }

    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << endl;
}
