#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll n, s;

int main() {
    cin >> n >> s;

    ll l = 1, r = n, cnt =0; 
    while(l <= r) {
        ll m = l  + ((r - l) >> 1);
        //cout << m << endl;
        ll cur = m, d = 0;
        while(cur) {
            d += cur % 10;
            cur /= 10;
        }
        //cout << d << " " << s << " " << m << endl;
        if(m - d >= s) { cnt += r - m + 1; r = m - 1;}
        else l = m + 1;
    }
    cout << cnt << endl;
    //ll t = m, d = 0, s = 0, l = 0;
/*    while(t) {*/
        //s += 9 * pow(10, d - 1);
        //d++;
        //t /= 10;
        ////cout << t << " " << s <<  endl;
    //}

    //if(d < 19) {
    //d++;
    //s += 9 * pow(10, d - 2);
    //}
    ////cout << s << " " << d << endl;
    //for(int i = d; i >= 2; --i) {
        ////cout << "***" << m << " " << s << " ";
        ////cout << l << " ";
        ////cout << m / s << " ";;


        //l += m / s * pow(10, i - 1);
        ////cout << l << endl;
        //m %= s;
        //cout << "***" << l << " " << m << endl;
        //s -= pow(10, i - 2) * 9;
        
    //}
    ////cout <<m << endl;
    //if(m > 0) l += 10;
    ////cout << l << endl;
    /*cout << max(n - l + 1, 0ll) << endl;*/
}
