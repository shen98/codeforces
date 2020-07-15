#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define N 100005
#define LL long long
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
	return sum;
}
int n,a[N],b[N],f[N];
LL maxn,sum[N],ans[N];
inline int find(int x)
{
	if(f[x]==x) return x;
	f[x]=find(f[x]); return f[x];
}
int main( )
{
	int i,j,x,y;
	n=read( );
	for(i=1;i<=n;i++) a[i]=read( );
	for(i=1;i<=n;i++) b[i]=read( );
	for(i=n;i>=2;i--)
		{
			x=b[i];
			f[x]=x;sum[x]=a[x];
            cout << endl;
            cout << "***" << find(x - 1) << " " << find(x + 1) << endl;
			if(x!=1&&f[x-1]) {y=find(x-1);f[y]=x;sum[x]+=sum[y];}
			if(x!=n&&f[x+1]) {y=find(x+1);f[y]=x;sum[x]+=sum[y];}

            for(int i = 1; i <= n; ++i) cout << f[i] << " ";
            cout << endl;
            for(int i = 1; i <= n; ++i) cout << sum[i] << " ";
            cout << endl;
			maxn=max(maxn,sum[x]);
			ans[i-1]=maxn;
		}
	for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
