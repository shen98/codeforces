#include <iostream>

using namespace std;

const int N = 1e6 + 5;

int n, p = 1;
int ans[N], seq[N];

void solve(int n, int mul) {
    if(n == 1) { ans[p++] = mul; return; }
    if(n == 2) { ans[p++] = mul; ans[p++] = mul * 2; return; }
    if(n == 3) { ans[p++] = mul; ans[p++] = mul; ans[p++] = mul * 3; return; }

    for(int i = 1; i <= n; ++i) if(seq[i] & 1) ans[p++] = mul;
    for(int i = 1; i <= n / 2; ++i) seq[i] = seq[i * 2] / 2;
/*    cout << "***  ";*/
    //for(int i = 1; i <= n / 2; ++i) cout << seq[i] << " ";
    /*cout << endl;*/
    solve(n / 2, mul * 2);
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        seq[i] = i;
    }
    solve(n, 1);
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
