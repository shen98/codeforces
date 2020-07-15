#include <iostream>
#include <string>
using namespace std;

string digit[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

string s[2005];
int d[2005][15], dp[2005][2005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        cin >> s[i];
        for(int k = 0; k < 10; ++k) {
            for(int j = 0; j < 7; ++j) {
                char x = s[i][j], y = digit[k][j];
                if(x == '1' && y == '0') { d[i][k] = -1; break; }
                if(x == '0' && y == '1') ++d[i][k];
            }
        }
    }

    dp[n][0] = 1;

    for(int i = n; i > 0; --i) {
        for(int j = 0; j <= m; ++j) {
            if(dp[i][j]) {
                for(int k = 0; k < 10; ++k) {
                    if(d[i - 1][k] != -1 && j + d[i - 1][k] <= m) {
                        dp[i - 1][j + d[i - 1][k]] = 1;
                    }
                }
            }
        }
    }

    if(dp[0][m] == 0) { cout << "-1\n"; return 0; }
    for(int i = 0; i < n; ++i) {
        int now = -1;
        for(int y = 9; y >= 0; --y) {
            if(d[i][y] != -1 && m >= d[i][y] && dp[i + 1][m - d[i][y]]) {
                now = y;
                m -= d[i][y];
                break;
            }
        }
        //assert(now != -1);
        cout << now;
    }
    cout << "\n";
    return 0;
}
