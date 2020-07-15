#include <stdio.h>
typedef long long ll;

const int m = 1e9 + 7;
int n;

int main() {
    scanf("%i", &n);
    if(n == 1) { printf("1\n"); return 0;}
    else if(n == 2) { printf("3\n"); return 0; }
    ll a = 1, b = 2, ans = 3;
    for(int i = 3; i <= n; ++i) {
        ll tmp = (a + b) % m;
        a = b;
        b = tmp;
        ans = (ans + tmp) % m;
    }
    
    printf("%lld\n", ans);
}
