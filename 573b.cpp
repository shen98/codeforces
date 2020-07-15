#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
int n;
int res[N], t[N];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> t[i];

    int worst = 0;
    for(int i = 1; i <= n; ++i) {
        worst = min(worst, t[i] - i);
        res[i] = i + worst;
    }

/*    for(int i = 1; i <= n; ++i) cout << res[i] << " ";*/
    /*cout << endl;*/
    worst = n + 1;
    for(int i = n; i >= 1; --i) {
        worst = min(worst, t[i] + i);
        res[i] = min(res[i], worst - i);
    }
/*    for(int i = 1; i <= n; ++i) cout << res[i] << " ";*/
    /*cout << endl;*/
    int cnt = 0;
    for(int i = 1; i <= n; ++i) cnt = max(cnt, res[i]);

    
    cout << cnt << endl;
}
