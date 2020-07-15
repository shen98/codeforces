#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 5;
int v, m = 1e6;
int a[10];
string dp[N];

int main() {
    cin >> v;
    for(int i = 1; i <= 9; ++i) { cin >> a[i]; m = min(a[i], m); }
    int l = v / m; if(!l) { cout << -1 << endl; return 0; }

    while(l--) {
        for(int k = 9; k >= 1; --k) {
            if((v - a[k]) / m == l && v >= a[k]) {
                cout << k;
                v -= a[k];
                break;
            }
        }
    }
}
