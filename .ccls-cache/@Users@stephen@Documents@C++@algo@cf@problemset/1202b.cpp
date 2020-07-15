#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e6 + 5;
string s;

int main() {
    cin >> s;
    int n = s.size();
    for(int i = 0; i <= 9; ++i) {
        for(int j = 0; j <= 9; ++j) {
            int dp[15][15];
            int ans = 0;
            for(int x = 0; x <= 9; ++x)
                for(int y = 0; y <= 9; ++y) dp[x][y] = 1e9;
            for(int v = 0; v <= 9; ++v) {
                for(int x = 0; x <= 9; ++x) {
                    for(int y = 0; y <= 9; ++y) {
                        if(x + y == 0) continue;
                        int to = (v + x * i + y * j) % 10;
                        dp[v][to] = min(dp[v][to], x + y);
                        //cout << "***" << v << " " << to << " " << dp[v][to] << endl;;
                    }
                }
            }

/*            for(int x = 0; x <= 9; ++x) {*/
                //for(int y = 0; y <= 9; ++y) cout << dp[x][y] << " ";
                //cout << endl;
            /*}*/
            for(int k = 0; k < n - 1; ++k) {
                if(dp[s[k] - '0'][s[k + 1] - '0'] == 1e9) { ans = -1; break; }
                ans += dp[s[k] - '0'][s[k + 1] - '0'] - 1;
            }
    
            cout << ans << " ";
        }
        cout << endl;
    }
}
