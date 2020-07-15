#include <iostream>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int pd = 0, ph = 0, Max = 0;
    bool f = 1;
    for(int i = 1; i <= m; ++i) {
        //cout << i << endl;
        int d, h;
        cin >> d >> h;
        //cout << 1 << endl;
        if(pd == 0) {
            Max = h + d - 1;
        } else {
            if(abs(d - pd) < abs(h - ph)) { f = 0; break; }
            Max = max(Max, (ph + h + d - pd) / 2);
        }
        pd = d; ph = h;
    }

    Max = max(Max, n - pd + ph);
    if(!f) cout << "IMPOSSIBLE" << endl;
    else cout << Max << endl;
}
