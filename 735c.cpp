#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

ll n, ans, p1, p2;

int main() {
    cin >> n;

    ans = 1;
    n -= 2;

    p1 = 1; p2 = 1;
    for(int i = 1; p1 <= n; ++i) {
        ans++;
        n -= p1;
        ll t = p2;
        p2 = p1;
        p1 += t;
    }

    cout << ans << endl;
    return 0;
}
