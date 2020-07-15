#include <iostream>

using namespace std;

int n, l = INT_MIN, r = INT_MAX, p, dif;

int main() {
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int c, d;
        cin >> c >> d;
        if(d == 1) {
            l = max(l, 1900 - dif);
        } else {
            r = min(r, 1899 - dif);
        }

        dif += c;
    }
    
    if(l > r) { cout << "Impossible" << endl; return 0; }
    if(r == INT_MAX) cout << "Infinity" << endl;
    else cout << r + dif << endl;

    return 0;
}
