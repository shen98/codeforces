#include <iostream>
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 5;
typedef long long ll;
ll n, l, p = 2;
int dp[N];
int main() {
    cin >> n;
    l = n - 2;
    for(int i = 3; i <= n; ++i) {
         l = (i * l + (i - 1) * (n - i)) % mod;
         p = (p * i) % mod;
         //cout << l << endl;
    }
    cout << (l + p) % mod << endl;
}
