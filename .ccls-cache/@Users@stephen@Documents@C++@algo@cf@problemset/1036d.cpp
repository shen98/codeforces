#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <cstdio>

using namespace std;

char _buf[1<<16];
int _bufpos,_buflen;
inline char getc(){
	if (_bufpos==_buflen)	_buflen=fread(_buf,1,1<<16,stdin),_bufpos=0;
	if (!_buflen)	return EOF;
	return _buf[_bufpos++];
}

template <class T>
inline void read(T &x)
{
	T f=1;x=0;
	char ch=getc();
	for (;!isdigit(ch) && ch!='-';ch=getc());
	if (ch=='-')	f=-1,ch=getc();
	for (;isdigit(ch);ch=getc())	x=x*10+ch-'0';
	x*=f;
}
const int N = 300005;
typedef long long ll;

int n, m;
int a[N], b[N];

int main() {
/*    cin >> n;*/
    //for(int i = 0; i < n; ++i) cin >> a[i];

    //cin >> m;
    /*for(int i = 0; i < m; ++i) cin >> b[i];*/
    read(n);
	for (int i=0;i<n;i++)	read(a[i]);
	read(m);
	for (int i=0;i<m;i++)	read(b[i]);

    ll tot = 0, ans = 0;
    tot = a[0] - b[0];
	if (tot==0)	ans++;
	int t1=0,t2=0;
	while (t1<n - 1 || t2< m - 1){
		if ((tot<0 || t2==m - 1) && t1< n - 1)	
			tot+=a[++t1];
		else tot-=b[++t2];
		if (tot==0)	ans++;
	}
	printf("%lld",tot?-1:ans);
    return 0;
}
