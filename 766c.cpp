#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int n, l = 0;
int a[30];
char s[1005];
ll dp[1005], num[1005];

int main() {
    cin >> n >> (s + 1);
    for(int i = 0; i < 26; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) num[i] = 1e9;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        int Min = a[s[i] - 'a'];
        for(int j = i; j >= 1; --j) {
            Min = min(Min, a[s[j] - 'a']);
            if(i - j + 1 > Min) break;
            else dp[i] = (dp[i] + dp[j - 1]) % mod;
            l = max(l, i - j + 1);
            num[i] = min(num[i], num[j - 1] + 1);
            //cout << "***" << i << " " << j << " " << dp[i] << endl;
        }
    }

/*    for(int i = 1; i <= n; ++i) cout << dp[i] << " ";*/
    /*cout << endl;*/
    cout << dp[n] << endl;
    cout << l << endl;
    cout << num[n] << endl;
}
