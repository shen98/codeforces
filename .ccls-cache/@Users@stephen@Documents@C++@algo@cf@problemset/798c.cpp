#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, Min=1e9, ans = 0, g, cnt = 0;
int a[N];
bool f = 1;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int main() {
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        g = gcd(g, a[i]);
        if(a[i] % 2) cnt++;
        else ans += (cnt / 2) + 2 * (cnt & 1), cnt = 0;
    }

    ans += (cnt / 2) + 2 * (cnt & 1);

    cout << "YES\n";
    cout << (g != 1 ? 0 : ans) << endl;
}
