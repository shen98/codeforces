#include <iostream>
#include <vector>
using namespace std;

int q;
const int MAX = 2e5 + 10;
int a[MAX];

int main() {
    cin >> q;

    for(int i = 0; i < q; ++i) {
        int h, n;
        cin >> h >> n;

        for(int i = 1; i <= n; ++i) cin >> a[i];

        int ans = 0;
        a[n + 1] = 0;
        for(int i = 2; i <= n; ++i) {
            if(a[i] - 1 == a[i + 1]) i++;
            else ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
