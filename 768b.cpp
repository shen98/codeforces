#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll n, l, r;


vector<ll> v;
int main() {
    cin >> n >> l >> r;
/*    while(n > 1) {*/
        //v.push_back(n);
        //n /= 2;
    /*}*/

    //for(auto a : v) cout << a << endl;
    if(n == 0) { cout << 0 << endl; return 0; }
    int num = 0;
    int m = ceil(log2(n));
    //cout << 123 << " " << m << endl;
    for(ll i = l; i <= r; ++i) {
        ll cur = i;
        while((cur & (cur - 1)) != 0) {
            cur -= cur & (cur - 1);
        }
        int s = log2(cur);
        //cout << "***" << i << " " << cur << " " << s << endl;
        if(s == 0) num++;
        else if(n >> (m - s - 1) & 1) num++;
        //cout << "***" <<  i << " " << n << endl;
    }

    cout << num << endl;

    return 0;
}
