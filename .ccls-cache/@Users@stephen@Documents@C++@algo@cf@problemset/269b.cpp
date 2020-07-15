#include <iostream>
using namespace std;
int n, m, ans = 0;
double x;
int a[5005], dp[5005];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i] >> x;

    for(int i = 1; i <= n; ++i) {
        int j = a[i];
        for(int k = j; k >= 1; --k) 
            dp[j] = max(dp[j], 1 + dp[k]);
    }

    for(int i = 1; i <= m; ++i) ans = max(ans, dp[i]);
    cout << n - ans << endl;
}
