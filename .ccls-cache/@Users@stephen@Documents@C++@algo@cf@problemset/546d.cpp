#include<cstdio>
 
int a[5555555];
 
int main()
{
	int i,j,k,n;
	for(i=2;i<=5000000;i++)
	{
		if(!a[i])for(j=1;i*j<=5000000;j++)for(k=i*j;k%i==0;k/=i)a[i*j]++;
		a[i]+=a[i-1];
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		printf("%d\n",a[j]-a[k]);
	}
}


/*#include <iostream>*/

//using namespace std;

//const int N = 5e6 + 5;
//int cnt[N];
//int main() {
    //ios::sync_with_stdio(false);
    //int t;
    //cin >> t;

    //for(int i = 2; i <= 5e6; ++i) {
        //if(!cnt[i]) {
            //for(int j = 1; i * j <= 5e6; ++j) {
                //for(int k = i * j; k % i == 0; k /= i) cnt[i * j]++;
            //}
        //}
        //cnt[i] += cnt[i - 1];
    //}

//[>    for(int i = 1; i <= 100; ++i) cout << cnt[i] << " ";<]
    //[>cout << endl;<]
    //while(t--) {
        //int j = 0, k = 0;
		//scanf("%d %d",&j,&k);
		//printf("%d\n",cnt[j]-cnt[k]);
//[>        int a, b;<]
        ////cin >> a >> b;

        //[>cout << cnt[a] - cnt[b] << endl;<]
    //}
/*}*/
