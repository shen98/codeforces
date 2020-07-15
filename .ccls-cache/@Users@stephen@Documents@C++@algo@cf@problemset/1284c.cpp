#include <iostream>

using namespace std;
typedef long long ll;
const int N = 250005;
int n, m;
ll fact[N], ans;

int main() {
    cin >> n >> m;
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % m;

    for(int i = 1; i <= n; ++i) {
        ans += (n - i + 1) * (fact[i] * fact[n - i + 1] % m);
        ans %= m;
    }

    cout << ans << endl;
    return 0;
}
