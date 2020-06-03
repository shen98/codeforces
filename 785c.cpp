#include <iostream>

using namespace std;

typedef long long ll;

ll n, m, ans;

int main() {
    cin >> n >> m;

    if(n <= m) { cout << n << endl; return 0; }
    n -= (m + 1);
    ans = m + 1;


    for(int i = 2; ; i++) {
        if(n <= 0) break;
        n -= i;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
