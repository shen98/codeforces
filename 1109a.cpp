#include <iostream>
#include <vector>

using namespace std;

const int N = 300005;
const int maxA = (1 << 20) + 3;
typedef long long ll;

ll b[2][maxA], a[N];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll x = 0, res = 0;

    b[1][0] = 1;
    for(int i = 0; i < n; ++i) {
        x ^= a[i];
        res += b[i % 2][x]++;
    }

    cout << res << endl;
    return 0;
}
