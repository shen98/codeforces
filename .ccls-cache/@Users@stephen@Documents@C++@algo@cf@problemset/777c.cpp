#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
int n, m, k;

//int Max[N], cur[N], t[N], s[N];
int g[N], s[N], a[N];

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int tmp;
            cin >> tmp;
            if(tmp >= a[j]) s[j]++;
            else s[j] = 1;
            a[j] = tmp;
            g[i] = max(g[i], s[j]);
        }
    }

    cin >> k;
    for(int i = 1; i <= k; ++i)  {
        int l, r;
        cin >> l >> r;
        if(g[r] >= r - l + 1) cout << "Yes\n";
        else cout << "No\n";
    }
/*    for(int i = 1; i <= n; ++i) {*/
        //for(int j = 1; j <= m; ++j) {
            //cin >> cur[j];
            //if(cur[j] >= Max[j]) {
                //if(s[j] == 0) s[j] = i;
            //}  else {
                //t[s[j] - 1]--; t[i - 1]++;
                //s[j] = i;
            //}
            //Max[j] = max(Max[j], cur[j]);
        //}
    //}

    //for(int i = n; i >= 0; --i) {
        //t[i] += t[i + 1];
    //}

    //cin >> k;
    //for(int i = 1; i <= k; ++i) {
        //int l, r;
        //cin >> l >> r;
    /*}*/
}
