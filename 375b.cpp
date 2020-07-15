
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 5005;
int n, m;
int g[N][N], r[N][N], c[N][N];
char s[N][N];
int main() {
std::ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> (s[i] + 1);
        //scanf("%s", (s[i] + 1));
    }

    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n; ++i) {
            r[i][j] = (s[i][j] == '1' ? r[i][j - 1] + 1 : 0);
            c[j][r[i][j]]++; 
            //c[i][j] = (g[i][j] ? c[i - 1][j] + 1 : 0);
        }
    }

/*    for(int i = 1; i <= n; ++i) {*/
        //for(int j = 1; j <= m; ++j) cout << r[i][j] << " ";
        //cout << endl;
    /*}*/
    int ans = 0;
    for(int i = 1; i <= m; ++i) {
/*        vector<int> cur(N);*/
        //for(int j = 1; j <= n; ++j) {
            //cur[r[j][i]]++;
            //cur[0]--;
        /*}*/
/*        cout << "***" << endl;*/
        //for(int j = 0; j <= m; ++j) cout << cur[j] << " ";
        /*cout << endl;*/
        for(int j = m; j >= 1; --j) {
            c[i][j] += c[i][j + 1];
            ans = max(ans, c[i][j] * j);
            //if(cur[j] >= j) { ans = max(j, ans); break; }
        }
/*        for(int j = 0; j <= m; ++j) cout << cur[j] << " ";*/
        /*cout << endl;*/
    }

    cout << ans << endl;
/*    for(int k = 1; k <= min(n, m); ++k) {*/
        //bool f = 0;
        //for(int i = 1; i <= n - k + 1; ++i) {
            //for(int j = 1; j <= m - k + 1; ++j) {
                //if( )
            //}
        //}
    /*}*/
}


/*#include <iostream>*/
//#include <string>
////#include <vector>
//using namespace std;

//const int N = 5005;
//int n, m, a[N], b[N], r, i, j;
//char s[N][N];

/*int main() {*/
  //scanf("%d%d",&n,&m);
  //for (i=0; i<n; i++) cin >> (s[i]);
  //for (j=0; j<m; j++) {
    //for (i=0; i<=m; i++) a[i]=0;
    //for (i=0; i<n; i++) {
      //if (s[i][j]=='0') b[i]=0; else b[i]++;
      //a[b[i]]++;
    //}
    //for (i=m; i>=0; i--) {
      //a[i]+=a[i+1];
      //if (a[i]*i>r) r=a[i]*i;
    //}
  //}
  //cout << r << endl;
  ////printf("%d\n",r);
  //return 0;
/*}*/
/*int main() {*/
    //cin >> n >> m;

    //for(int i = 1; i <= n; ++i) cin >> (s[i] + 1);

    //for(int j = 1; j <= m; ++j) {
        //for(int i = 1; i <= m; ++i) a[i] = 0;
        //for(int i = 1; i <= n; ++i) {
            //if(s[i][j] == '0') b[i] = 0;
            //else b[i]++;
            //a[b[i]]++;
        //}
        //for(int i = m; i >= 1; --i) {
            //a[i] += a[i + 1];
            //if(a[i] * i > r) r = a[i] * i;
        //}
    //}

    //cout << r << endl;

/*}*/
