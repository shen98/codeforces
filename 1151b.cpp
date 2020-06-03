#include <iostream>
#include <vector>
using namespace std;

const int N = 505;
int a[N][N];
int n, m;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> a[i][j];
    }

    int num = a[0][0];
    for(int i = 1; i < n; ++i) num ^= a[i][0];

    if(num > 0) {
        cout << "TAK" << endl;
        for(int i = 0; i < n; ++i) cout << 1 << " ";
        cout << endl;
        return 0;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if(a[i][j] != a[i][0]) {
                cout << "TAK\n";
                for(int k = 0; k < n; ++k) {
                    if(k != i) cout << 1 << " ";
                    else cout << j + 1 << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "NIE" << endl;

    return 0;
}
