
#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;

LL l,r,ans;

int main() {
	scanf("%I64d%I64d",&l,&r);
	LL ans=1ll<<62;
	while ((ans)&&((ans&l)==(ans&r))) ans>>=1;
	printf("%I64d\n",max(0ll,ans+ans-1ll));
	return 0;
}
/*#include <iostream>*/

//using namespace std;

//typedef long long ll;

//ll r, l;

//int main() {
    //cin >> l >> r;

    //for(ll s = l + 1; s <= r; s ^= (-s - 1)) {
        //cout << s << endl;
    //}
/*}*/
