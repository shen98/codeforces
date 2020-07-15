#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//typedef pair<int, int> pii;

const int N = 1e5 + 5;
int n;
int dp[N], a[N], p[N];
//vector<pii> v(N);
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }

    for(int x = n; x >= 1; --x) {
        int i = p[x];
        dp[i] = 1;
        for(int j = x; i + j <= n; j += x) {
            if(a[j + i] > a[i]) dp[i] = min(dp[i], dp[j + i]);
        }

        for(int j = x; i - j >= 1; j += x) {
            if(a[i - j] > a[i]) dp[i] = min(dp[i], dp[i - j]);
        }

        cout << x << " " << dp[i] << endl;
        dp[i] ^= 1;
    }
    for(int i = 1; i <= n; ++i) cout << (dp[i] ? "A" : "B");
}
