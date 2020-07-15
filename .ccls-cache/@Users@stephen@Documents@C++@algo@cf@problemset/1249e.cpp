#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, c;
int a[N], b[N], dp[N][2];
int main() {
    cin >> n >> c;
    for(int i = 1; i <= n - 1; ++i) cin >> a[i];
    for(int i = 1; i <= n - 1; ++i) cin >> b[i];
    dp[0][1] = c;
    cout << 0 << " ";
    for(int i = 1; i <= n - 1; ++i) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = min(dp[i - 1][1] + b[i], dp[i - 1][0] + c + b[i]);
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;
}
