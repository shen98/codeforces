#include <iostream>

using namespace std;

const int N = 1005;
int n, m, h, t = 0;
int a[N], c[N];

int main() {
    cin >> n >> m >> h;

    int tot = 0, num = 0;
    for(int i = 1; i <= m; ++i) {
        int tmp;
        cin >> tmp;
        if(i != h) num += tmp;
        tot += tmp;
    }
    
    tot--;

    if(tot < n - 1) cout << -1 << endl;
    else {
        double rat = 1;
        for(int i = 0; i < n - 1; ++i) {
            //cout << "***" << rat << " " << num - i << " " << tot - i << endl;
            rat *= num - i;
            rat /= tot - i;
            //cout << i << " " << rat << endl;
        }
        double ans = 1 - rat;
        printf("%.10f\n", ans);
    }
}
