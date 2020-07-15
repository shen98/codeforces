#include <iostream>

using namespace std;
typedef long long ll;
int n;
int a[505][505], d[505], dp[505][505];
ll res[505];
int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> a[i][j];
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) dp[i][j] = 1e9;
    for(int i = 1; i <= n; ++i) dp[i][i] = 0;

    for(int i = 1; i <= n; ++i) cin >> d[i];

    for(int k = n; k >= 1; --k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) 
                a[i][j] = min(a[i][j], a[i][d[k]] + a[d[k]][j]);
        }
/*        for(int i = k + 1; i <= n; ++i) dp[d[k]][d[i]] = a[d[k]][d[i]];*/
        //for(int i = n; i >= k; --i) {
            //int x = d[i], y = d[k];
            ////dp[y][x] = a[y][x];
            //for(int j = n; j >= k; --j) {
                //dp[x][y] = min(dp[x][y], dp[x][d[j]] + a[d[j]][y]);
                //dp[y][x] = min(dp[y][x], dp[y][d[j]] + a[d[j]][x]);
            //}
        //}

        //for(int i = n; i >= k; --i) {
            //for(int j = n; j >= k; --j) {
                //int x = d[i], y = d[j];
                //dp[x][y] = min(dp[x][y], dp[x][d[k]] + a[d[k]][y]);
            //}
        /*}*/

        ll ans = 0;
        for(int i = n; i >= k; --i) {
            for(int j = n; j >= k; --j) {
                //cout << dp[d[i]][d[j]] << " ";
                ans += a[d[i]][d[j]];
            }
            //cout << endl;
        }

        res[k] = ans;
        //cout << ans << " ";
        //ans
/*        for(int i = 1; i <= n - k + 1; ++i) {*/
            //for(int j = 1; j <= n - k + 1; ++j) {
                //int x = d[i], y = d[j];
                //dp[x][y] = min(dp[x][y], a[x][y] + dp[x][x]);
            //}
        /*}*/
    }

    for(int i = 1; i <= n; ++i) cout << res[i] << " ";

}
