#include <iostream>
using namespace std;

int n, m;
int a, b, c, d, dp[1005];

int main() {
    cin >> n >> m >> c >> d;
    for(int i = c; i <= n;  i++)
        dp[i] = dp[i - c] + d;

    for(int i = 1; i <= m; ++i) {
        cin >> a >> b >> c >> d;

        //cout << a / b << endl;
        for(int j = 0; j < a / b; ++j) {
            for(int k = n; k >= c; k--)
                dp[k] = max(dp[k], dp[k - c] + d);
        }
    }

    cout << dp[n] << endl;
}
