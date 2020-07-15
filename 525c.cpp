#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
int n;
ll ans = 0;
ll a[N];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    sort(a, a + n + 1, [](int a, int b){
                return a > b;
            });

/*    for(int i = 0; i <= n; ++i) cout << a[i] << " ";*/
    /*cout << endl;*/
    int p = 0;
    for(int i = 0; i <= n; ++i) {
        if(a[i] - a[i + 1] < 2) {
            if(!p) p = a[i + 1];
            else { ans += p * a[i + 1]; p = 0; }
            i++;
        }
    }

    cout << ans << endl;
}
