#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}
 
inline int getint(){
  int x;
  char c=nc(),b=1;
  if(c == -1)
	return 0;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
  return x;
}
const int N = 1010101;
int a[N];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            a[i] = getint();
        }

        sort(a + 1, a + n + 1);
        int e = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i] == a[i + 1]) a[++e] = a[i], ++i;
        }

        double ans = 0;
        int fn;

        for(int i = 1; i < e; ++i) {
            if(1.0 * a[i] / a[i + 1] > ans) {
                ans = 1.0 * a[i] / a[i + 1];
                fn = i;
            }
        }

        printf("%d %d %d %d\n", a[fn], a[fn], a[fn + 1], a[fn + 1]);
    }

    return 0;
}
