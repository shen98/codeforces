#include <iostream>

using namespace std;

typedef long long ll;

ll a, b;

void check(ll& a, ll& b) { if (a > b) swap(a, b); }

/*ll lcd(ll a, ll b) {*/
    //while(a) {
        //b %= a;
        //swap(a, b);
    //}
/*}*/

int main() {
    cin >> a >> b;
    for(int i = 1; i < b + 1; ++i) {

        if((a + 1) % i != 0) {
            cout << "No";
            return 0;
        }
    }

    cout << "yes";
    return 0;
}
