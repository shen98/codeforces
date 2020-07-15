#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pos, mn = 1e9;
    for(int i = 1; i <= n; ++i) {
        int j = n / i + (n % i != 0);
        if(i + j < mn) { pos = i; mn = i + j; }
    }

    int now = n;
    while(now) {
        for(int i = max(1, now - pos + 1); i <= now; ++i) cout << i << " ";
        now = max(0, now - pos);
    }
    //for(int i = n / 2 + 1; i <= n; ++i) cout << i << " ";
    //for(int i = 1; i <= n / 2; ++i) cout << i <<  " ";
    /*cout << endl;*/
}
