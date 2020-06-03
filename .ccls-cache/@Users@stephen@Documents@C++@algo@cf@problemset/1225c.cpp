#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 1e9;
ll n, p;

int main() {
    cin >> n >> p;

    int ans = INT_MAX;
    bool ok = false;
    for(int i = 1; i <= 32; ++i) {
        if(n - i * p <= 0) break;
         int t = n - i * p, cur = 0;
        for(int j = 0; j < 32; j++) cur += (bool)(t & (1 << j));
        if(cur <= i && t >= i) {
            cout << i << endl;
            ok = true;
            break;
        }
    }

    if(!ok) cout << -1 << endl;
    return 0;
}
