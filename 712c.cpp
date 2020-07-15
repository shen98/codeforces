#include <iostream>

using namespace std;

int x, y, ans = INT_MAX, k = 0;

int main() {
    cin >> x >> y;
    int a = y, b = y, c = y;

    int t = 0;
    while(1) {
        if(a >= x && b >= x && c >= x) {
            cout << t << endl;
            break;
        }
        t++;

        if(t % 3 == 1) a = b + c - 1;
        else if(t % 3 == 2) b = a + c - 1;
        else c = a + b - 1;
    }


}
