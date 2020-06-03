#include <iostream>
//#include <bits/stdc++.h>
//#include <boost/math/common_factor.hpp>

using namespace std;

typedef long long ll;

ll n, a, b, p, q, sum;

ll gcd(ll a, ll b) {
    while (b) a %= b, swap(a, b);
    return a;
}
 
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    cin >> n >> a >> b >> p >> q;

    sum += p * (n / a) + q * (n / b);

    ll t = lcm(a, b);
    if(p > q) sum -= q * (n / t);
    else sum -= p * (n / t);

    cout << sum << endl;

    return 0;
}
