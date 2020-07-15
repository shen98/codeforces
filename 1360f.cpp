#include <iostream>
#include <set>
#include <string>
using namespace std;

int dp[15];
string a[15];

int n, m;

bool ok(string cur) {
    for(int i = 1; i <= n; ++i) {
        int df = 0;
        for(int j = 0; j < m; ++j) {
            if(a[i][j] != cur[j]) df++;
        }
        if(df > 1) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        for(int i = 1; i <= n; ++i) cin >> a[i];
        string ans = "-1";
        for(int i = 0; i < m; ++i) {
            for(int k = 0; k < 26; ++k) {
                string cur = a[1];
                cur[i] = k + 'a';
                if(ok(cur)) ans = cur;
            }
        }
        cout << ans << endl;
    }
}
