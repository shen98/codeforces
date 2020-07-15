#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, k;
int a[N];
//unordered_map<ll, int> map;

int main() {
    cin >> n >> k;

    ll M = 0, ans = 0, c = 0;
    for(int i = 1; i <= n; ++i) {
        ll b; 
        cin >> b;
/*        map[b]++;*/
        /*M = max(b, M);*/
        a[b]++;
    }

    for(int i = N - 2; i >= 0; --i) {
        a[i] += a[i + 1];
    }

    for(int i = N - 1; a[i] < n; --i) {
        c += a[i];
        if(c >= k) { ans++; c = (c != k) ? a[i] : 0; }
    }
    if(c) ans++;
/*    for(ll i = M; i >= 0; --i) {*/
        //if(map[i] + c >= k) { 
            //ans++; 
            //if(c != k) c = map[i]; 
            //else c = 0;
        //} else if(map[i] + c < k) {
            //c += map[i];
        //}
        //if(map[i] == n) break;
        //map[i - 1] += map[i];
        //map[i] = 0;
    /*}*/

    cout << ans << endl;
}
