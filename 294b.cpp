#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, t, w, cnt1 = 0, cnt2 = 0, ans = 1e9;
int dp[5][105];
int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> t >> w;
        if(t == 1) dp[1][cnt1++] = w;
        else dp[2][cnt2++] = w;
    }

    sort(dp[1], dp[1] + cnt1);
    sort(dp[2], dp[2] + cnt2);

    for(int i = 0; i <= cnt1; ++i) {
        for(int j = 0; j <= cnt2; ++j) {
            int s = 0;
            for(int x = 0; x < cnt1 - i; ++x) s += dp[1][x];
            for(int x = 0; x < cnt2 - j; ++x) s += dp[2][x];

            if(i + 2 * j >= s && ans > i + j * 2)
                ans = i + j * 2;
        }
    }
    cout << ans << endl;
}
