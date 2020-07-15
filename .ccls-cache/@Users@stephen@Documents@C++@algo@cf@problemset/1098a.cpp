#include <iostream>

using namespace std;
typedef long long ll;
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
const int N = 100005;
int n;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll fa[N], s[N];

int main() {
    cin >> n;

    for(int i = 2; i <= n; ++i) cin >> fa[i];
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        if(s[i] == -1) s[i] = inf;
        else chkmin(s[fa[i]], s[i]);
    }

 /*   for(int i = 1; i <= n; ++i) cout << s[i] << " ";*/
    /*cout << endl;*/
    ll cnt = 0;
    for(ll i = n; i; --i) {
        if(s[i] == inf) s[i] = s[fa[i]];
        s[i] -= s[fa[i]];
        cnt += s[i];
        if(s[i] < 0) { cout << -1 << endl; return 0; }
    }

    cout << cnt << endl;

    return 0;
}
