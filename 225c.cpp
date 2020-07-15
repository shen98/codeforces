#include <iostream>
#include <string>
using namespace std;

int n, m, x, y;
char c[1005][1005];
int dp[1005][2], cnt[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x >> y;

    for(int i = 1; i <= m; ++i) dp[i][0] = dp[i][1] = 1e9;
    for(int i = 1; i <= n; ++i) {
        cin >> (c[i] + 1);
        //for(int j = 0; j < m; ++j) if(s[j] == '#') cnt[i]++;
    }

    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(c[i][j] == '#')  cnt[j]++;
        }
    }

    //dp[1][0] = cnt[1]; dp[1][1] = m - cnt[1];
/*    for(int i = 1; i <= n; ++i) cout << cnt[i] << " ";*/
    /*cout << endl;*/
    for(int j = 1; j <= m; ++j) {
        int A = 0, B = 0;
        int k = j;
        //cout << j - x + 2 << endl;
        for(k = j; k >= 1 && k >= j - x + 2; --k) {
            //cout << 9999999999999<< endl;
            A += cnt[k]; B += n - cnt[k];
        }
        //cout << "$$" << A << " " << B << endl;
        for(; k >= 1 && k >= j - y + 1; --k) {
            //cout << 123123123 << endl;
            A += cnt[k], B += n - cnt[k];
            //cout << "***" << k << " " << A << " " << B << " " << dp[k - 1][1] << " " << dp[k - 1][0] << " " << endl;
            dp[j][0] = min(dp[j][0], dp[k - 1][1] + A);
            dp[j][1] = min(dp[j][1], dp[k - 1][0] + B);
            //cout << j << " " << dp[j][0] << " " << dp[j][1] << endl;
        }
        //for(int k = j - 1; k >= 0 || k >= j - y)
    }
    cout << min(dp[m][0], dp[m][1]) << endl;
}
