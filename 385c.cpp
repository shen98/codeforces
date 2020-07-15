#include <iostream>
#include <map>
#include <bitset>
using namespace std;

const int N = 1e7 + 5;
int n, m, l, r, cnt[N], pre[N];
//map<int, int> cnt;
bitset<N> sieve;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int sum;
    for(int i = 2; i <= 1e7; ++i) {
        if(!sieve[i]) {
            sum = 0;
            for(int j = i; j <= 1e7; j += i) {
                sieve[j] = 1;
                sum += cnt[j];
            }
            pre[i] = pre[i - 1] + sum;
        } else 
            pre[i] = pre[i - 1];
    }

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> l >> r;
        sum = pre[min((int)1e7, r)] - pre[min((int)1e7, l - 1)];
        cout << sum << endl;
    }
/*    for(int i = 1; i <= n; ++i) {*/
        //int a;
        //cin >> a;
        //for(int j = 1; j * j <= a; ++j) {
            //if(a % j == 0) { cnt[j]++; cnt[a / j]++; }
        //}
    //}

    //cin >> m;

    //for(int i = 1; i <= m; ++i) {
        //int l, r;
        //cin >> l >> r;
        //for(int i = )
    /*}*/
}
