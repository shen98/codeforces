#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n, m;
int a[N], dp[N][2];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> a[i];

    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] > a[i - 1]) {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = 1;
        } else if(a[i] < a[i - 1]) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = 1;
        } else {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = dp[i - 1][0] + 1;
        }
    }

/*    for(int i = 1; i <= n; ++i) cout << dp[i][0] << " ";*/
    //cout << endl;
    //for(int i = 1; i <= n; ++i) cout << dp[i][1] << " ";
    /*cout << endl;*/
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        int d = dp[r][0];
        int t = d + dp[r - d][1];

        //cout << "***" << d << " " <<t << endl;
        cout << (t >= r - l + 1 ? "Yes" : "No") << endl;
    }
}
