#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[105][105][105], Max = 1e17, p[105][105];
int n, c[105], m, k;

ll sol(int x, int prev, int sum) {
    if(x == n + 1) {
        if(sum == k) return 0;
        return Max;
    }
    ll &ret = dp[x][prev][sum];
    if(ret != -1) return ret;
    ret = Max;
    bool is = (c[x] == 0);
    if(is) {
        int i;
        for(i = 1; i <= m; ++i) {
            if(prev == i) 
                ret = min(ret, p[x][i] + sol(x + 1, i, sum));
            else 
                ret = min(ret, p[x][i] + sol(x + 1, i, sum + 1));
        }
    } else {
        if(prev == c[x])
            ret = sol(x + 1, prev, sum);
        else 
            ret = sol(x + 1, c[x], sum + 1);
    }
    return ret;
}

int main() {
    int i, j;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> p[i][j];

    memset(dp, -1, sizeof dp);

    ll ret = sol(1, 0, 0);
    if(ret >= Max) ret = -1;
    cout << ret << endl;
}
