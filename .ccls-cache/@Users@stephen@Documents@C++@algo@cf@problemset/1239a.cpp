#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
int dp[N][2], c[N][2];

int main() {
    cin >> n >> m;
    dp[1][0] = 2;
    dp[1][1] = 0;
    for(int i = 2; i <= max(n, m); ++i) {
        dp[i][0] = dp[
        dp[i][1] = dp[i - 1][1] + dp[i - 1][0] - dp[i - 2][1];
    }
    cout << (dp[n][0] + dp[n][1]) +  << endl;
}
