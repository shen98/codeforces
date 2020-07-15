#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
string s, t;

int main() {
    cin >> s >> t;

    ll a = s.size(), b = t.size();

    ll tem = 0, z[a + 2];
    z[0] = 0;

    for(int i = 0; i < a; ++i) {
        if(tem != b) {
            if(s[i] == t[tem]) tem++;
        }
        z[i + 1] = tem;
    }

    z[a + 1] = z[a];
    /*for(auto a : z) cout << a << " ";*/
    /*cout << endl;*/
    ll zz[a + 2];
    zz[a + 1] = 0;
    tem = 0;

    for(int i = a - 1; i >= 0; --i) {
        if(tem != b) {
            if(s[i] == t[b - 1 - tem]) tem++;
        }
        zz[i + 1] = tem;
    }
    zz[0] = zz[1];
    a += 2;

   /* for(auto a : zz) cout << a << " ";*/
    /*cout << endl;*/
    ll ans = 0;
    for(int i = 0; i < a; ++i) {
        ll p = b - zz[i];
        auto it = lower_bound(z, z + a, p);
        ll k = it - z;
        ans = max(ans, i - k - 1);
    }

    cout << ans << endl;
    return 0;
}

