#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int t, n, k;
ll a[N];

int main() {
    cin >> t;

    while(t--) {
        cin >> n >> k;

        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        ll sum = 0, Min = LONG_MAX, pos = LONG_MAX;
        for(int i = k + 1; i <= n; ++i) {
            //sum += a[i];
            //if(i >= k + 1) {
                //sum -= a[i - k - 1];
            //cout << a[i] << endl;
/*                if(a[i] - a[i - k - 1] < Min) {*/
                    /*Min = a[i] - a[i - k - 1];*/
                    //cout << round(sum * 1.0 / (k + 1)) << endl;
                    //pos = round(sum * 1.0 / (k + 1));
            pos = min(pos, a[i - k] + (a[i] - a[i - k ]) / 2);
                //}
            //}
        }

        cout << pos << endl;
    }
}
