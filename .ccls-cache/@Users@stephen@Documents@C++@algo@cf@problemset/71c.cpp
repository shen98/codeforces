#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n;
int a[N];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> a[i];

/*    if(n % 2 == 1) {*/
        //bool f = 1;
        //for(int i = 1; i <= n; ++i) if(a[i] == 0) { f = 0; break; }
        //cout << (f ? "YES" : "NO") << endl;
    /*} else {*/
        for(int i = 1; i <= n / 3; ++i) {
            //cout << "***" << i << endl;
            if(n % i != 0) continue;
            //bool f = 1;
            for(int j = 1; j <= i; j++) {
                bool f = 1;
                for(int k = j; k <= n; k += i) {
                    //cout << "***" << i << " " << k << " " << a[k] << endl;
                    if(a[k] == 0) { f = 0; break; }
                }
                if(f) { cout << "YES" << endl; return 0; }
            }
        }
        cout << "NO" << endl;
    //}
}
