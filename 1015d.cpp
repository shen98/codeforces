#include <iostream>

using namespace std;
typedef long long ll;
ll n, k, s;

int main() {
    cin >> n >> k >> s;

    if(k * (n - 1) < s || k > s) { cout << "NO\n"; return 0; }
    cout << "YES\n";
    ll x = (n == 2 ? 0 : (s - k) / (n - 2));
    ll d = k - x;
    ll l = s - x * (n - 1);
    ll p = (x % 2 == 1 ? n : 1);
    ll s = (p == 1 ? 2 : n - 1);
    //cout << d << " " << l << " " << s << endl;
    for(ll i = 1; i <= x; ++i) {
        if(i % 2 == 1) cout << n << " ";
        else cout << 1 << " ";
    }

    for(ll i = 1; i <= d; ++i, l--) {
        if(i == d) cout << (p + l <= n ? p + l : p - l) << endl;
        else if(i % 2 == 1) { cout << s << " "; p = s; }
        else if(i % 2 == 0) { 
            p = (s == 2 ? 1 : n);
            cout << (s == 2 ? 1 : n) << " ";
        }
    }
}
