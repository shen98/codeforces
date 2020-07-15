#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}
 
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
const int N = 2e5 + 5;
ll c[N];
ll n, x, a, y, b;

ll getSum(int l, int m) {
    ll tmp = 0;
    ll g = lcm(a, b), p = m / g;
    ll numA = p * (g / a - 1) + ((m % g) / a);
    ll numB = p * (g / b - 1) + ((m % g) / b);
    //cout << endl;
    //cout << a << " " << b << " " << g << " " << p << " " << numA << " "<< numB << " " << endl;
    for(int i = n; i >= n - m + 1; --i) {
        if(p-- > 0) tmp += c[i] / 100 * (x + y);
        else {
            if(numA-- > 0) tmp += c[i] / 100 * x;
            else if(numB-- > 0) tmp += c[i] / 100 * y;
        }
    }

    return tmp;
}

int main() {
    int q;
    cin >> q;

    while(q--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> c[i];
        cin >> x >> a >> y >> b;
        if(y > x) { swap(x, y); swap(a, b); }
        ll k;
        cin >> k;

        sort(c + 1, c + n + 1);

        ll t = 0;
        ll l = 1, r = n;

        ll ans = 0;
        while(l <= r) {
            int m = (l + r) >> 1;
            ll sum = getSum(l, m);
            //cout << "***" << l << " " << r << " " << m << " " << sum << endl;
            if(sum < k) l = m + 1;
            else { ans = m; r = m - 1; }
        }
        if(ans == 0) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
