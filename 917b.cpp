#include <iostream>

using namespace std;

bool chk[30][101][101], win[30][101][101];
int n, m, c[101][101];

bool get(int k, int i, int j) {
    if(!chk[k][i][j]) {
        chk[k][i][j] = 1;
        for(int l = 1; l <= n; ++l) {
            if(c[i][l] >= k) {
                if(!get(c[i][l], j, l)) {
                    win[k][i][j] = 1;
                    break;
                }
            }
        }
    }
    return win[k][i][j];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        char s;
        cin >> x >> y >> s;
        c[x][y] = s - 'a' + 1;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) cout << (get(1, i, j) ? 'A' : 'B');
        cout << endl;
    }
}
