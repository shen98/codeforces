#include<iostream>
using namespace std;
int n, t;
double p;
double dp[2005][2005];
int main() {
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for(int i = 1; i <= t; ++i) dp[i][0] = dp[i - 1][0] * (1 - p);
    for(int i = 1; i <= t; ++i) {
        for(int j = 1; j <= i && j <= n; ++j) {
            dp[i][j] = dp[i - 1][j - 1] * p + (j < n ? (1 - p) : 1) * dp[i - 1][j];
            //cout << "***" << i << " " << j << " " << dp[i][j] << " " << dp[i - 1][j] << " " << dp[i - 1][j - 1] * max(p, 1-p) << " " << (j < i ? min(p, 1 - p) : 1) << endl;
        }
    }
    //cout << dp[1][1] << " " << n << " " << t << endl;
/*    for(int i = 1; i <= t; ++i) {*/
        //for(int j = 1; j <= n; ++j) cout << dp[i][j] << " ";
        //cout << endl;
    /*}*/
    
    double ans = 0.0;
    for(double i = 1; i <= n; ++i) ans += dp[t][(int)i] * i;
    //cout << ans << endl;
    printf("%.10f\n", ans) ;
    //cout << ans << endl;
}
