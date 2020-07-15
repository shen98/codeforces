#include <iostream>
#include <string>
using namespace std;

int n, q;
//int c[1505][1505][27];
string s;

int main() {
    cin >> n >> s >> q;

    while(q--) {
        int x, ans = 0, l = 0, a = 0, p = 0;
        char c;
        cin >> x >> c;

        for(int i = 0; i < n; ++i) {
            if(s[i] != c) l++;
            while(l > x) {
                if(s[p] != c) l--;
                p++;
            }
            ans = max(ans, i - p + 1);
        }
        cout << ans << endl;
    }
/*    for(int k = 1; k <= 26; ++k) {*/
        //char g = 'a' + k - 1;
        ////for(int i = 1; i <= n; ++i) c[0]
        //for(int i = 0; i <= n; ++i) {
            //for(int j = 1; j <= n; ++j) {
                //if(i == 0) { c[i][j][k] = (s[j - 1] == g ? 1 + c[i][j - 1][k] : 0); continue; }
                //if(s[j - 1] != g) c[i][j][k] = c[i - 1][j - 1][k] + 1;
                //else c[i][j][k] = c[i][j - 1][k] + 1;
            //}
        //}
    //}

    //for(int i = 1; i <= q; ++i) {
        //int m;
        //char cc;
        //cin >> m >> cc;
        //int Max = 0;
        //for(int j = 1; j <= n; ++j) {
            //Max = max(Max, c[m][j][cc - 'a' + 1]);
        //}
        //cout << Max << endl;
    /*}*/
/*    for(int i = 0; i <= n; ++i) {*/
        //for(int j = 0; j <= n; ++j)  cout << c[i][j]['a' - 'a' + 1] << " ";
        //cout << endl;
    /*}*/
}
