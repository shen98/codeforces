#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = (1ll << 32) - 1;
int main() {
    int l;
    cin >> l;
    stack<pll> stk;
    ll ans = 0;
    for(int i = 0; i < l; ++i) {
        string str;
        cin >> str;
        if(str == "add") {
            ++ans;
            if(ans > INF) break;
        } else if(str == "for") {
            int t;
            cin >> t;
            stk.emplace(ans, t);
        } else if(str == "end") {
            ll delta = ans - stk.top().first;
            ans += delta * (stk.top().second - 1);
            stk.pop();
            if(ans > INF) break;
        }
    }

    if(ans > INF) cout << "OVERFLOW!!!\n";
    else cout << ans << endl;
    return 0;
}
