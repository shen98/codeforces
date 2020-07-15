#include <iostream>
#include <cmath>
using namespace std;

int n, q;
int d[100];

int main() {
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        d[(int)log2(a)]++;
    }

    for(int i = 1; i <= q; ++i) {
        int b, ans = 0;
        cin >> b;
        int s = (int)log2(b);
        //bool f = 1;
        while(s >= 0) {
            int m = min(d[s], b / (int)pow(2, s));
            //cout << "***" << s << " " << m << endl;
            ans += m;
            b -= pow(2, s) * m;
            if(b == 0) break;
            s--;
        }

        //cout << b << endl;
        cout << (b == 0 ? ans : -1) << endl;
    }
}

