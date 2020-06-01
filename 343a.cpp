#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, ans;

ll solve(ll a, ll b) {
    if(a == b) return 1;
    if(a == 0 || b == 0) return 0;

    if(a > b) return a / b + solve(a % b, b);
    return b / a + solve(a, b % a);
}

int main() {
    cin >> a >> b;
        
    cout << solve(a, b) << endl;
    return 0;
}
