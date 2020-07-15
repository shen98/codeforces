#include <iostream>
using namespace std;
typedef long long ll;
ll s, x, res = 0;
ll dp[105], ans[105][5][2];
int main() {
    cin >> s >> x;
    
    if(s < x) { cout << 0 << endl; return 0; }
    if(s == x) res -= 2;
    int d = 1;

    while(x) {
        if(x & 1) dp[d] = 1;
        x >>= 1;
        d++;
    }

    d = 1; ans[0][0][0] = 1;
    while(s) {
        //cout << "***" << s << " " << (s&1) << " " << dp[d] << endl;
        if(s & 1) {
            if(dp[d]) {
                ans[d][1][0] = ans[d-1][0][0] + ans[d-1][1][0] + ans[d-1][2][0];
                ans[d][2][0] = ans[d-1][0][0] + ans[d-1][1][0] + ans[d-1][2][0];
            } else {
                ans[d][0][0] = ans[d-1][3][1] + ans[d-1][1][1] + ans[d-1][2][1];
                ans[d][3][1] = ans[d-1][3][1] + ans[d-1][1][1] + ans[d-1][2][1];
            }
        } else {
            if(dp[d]) {
                ans[d][1][1] = ans[d-1][3][1] + ans[d-1][1][1] + ans[d-1][2][1];
                ans[d][2][1] = ans[d-1][3][1] + ans[d-1][1][1] + ans[d-1][2][1];
            } else {
                ans[d][0][0] = ans[d-1][0][0] + ans[d-1][1][0] + ans[d-1][2][0];
                ans[d][3][1] = ans[d-1][0][0] + ans[d-1][1][0] + ans[d-1][2][0];
            }
        }
        s >>= 1;
        d++;
        //cout << d << endl;
    }

/*    for(int i = 1; i <= d; ++i) {*/
        //for(int j = 0; j < 4; ++j) cout << ans[i][j][0] << " " << ans[i][j][1] << " ";
        //cout << endl;
    //}
    /*cout << endl;*/
    for(int i = 0; i < 3; ++i) res += ans[d - 1][i][0];
    cout << res << endl;
}

