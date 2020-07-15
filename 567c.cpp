#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n, k;
int a[N];
map<int, ll> c1;
map<int, ll> c2;
int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] % (k * k) == 0 && i >= 3) ans += c2[a[i] / k];

        if(a[i] % k == 0 && i >= 2) c2[a[i]] += c1[a[i] / k];
        //cout << "***" << a[i] << " " << c1[a[i]] << " " << c2[a[i]] << endl;

        c1[a[i]]++;
    }

/*    for(int i = 1; i <= n; ++i) cout << c1[a[i]] << " ";*/
    //cout << endl;    
    //for(int i = 1; i <= n; ++i) cout << c2[a[i]] << " ";
    /*cout << endl;*/
    cout << ans << endl;
}
