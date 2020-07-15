#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 2e5 + 5;
int x[N], pre, p[N];
int n, m, s, d;

int main() {
    scanf("%i %i %i %i", &n, &m, &s, &d);
    for(int i = 1; i <= n; ++i) scanf("%i", &x[i]);
    sort(x + 1, x + 1 + n);
    pre = n;
    x[0] = -1;
    for(int i = n - 1; i >= 0; --i) {
        if(x[i + 1] - x[i] >= s + 2 && x[pre] - x[i + 1] <= d - 2) {
            p[i] = pre;
            pre = i;
        }
    }

    if(pre > 0) { printf("IMPOSSIBLE\n"); return 0; }
    for(int i = 0; i < n; i = p[i]) {
        printf("RUN %i\nJUMP %i\n", x[i + 1] - x[i] - 2, x[p[i]] - x[i + 1] + 2);
    }
    if(x[n] + 1 < m) printf("RUN %i\n", m - x[n] - 1);
}

/*#include <iostream>*/
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;

//typedef long long ll;
//typedef pair<char, ll> pci;
//const int N = 2e5 + 5;
//ll n, m, s, d;
//queue<ll> q;
//ll ob[N];
//vector<pci> v;

//int main() {
    //cin >> n >> m >> s >> d;
    //for(int i = 1; i <= n; ++i) cin >> ob[i];
    //sort(ob + 1, ob + n + 1);
    ////for(int i = 1; i <= n; ++i) cout << ob[i] << " ";
    ////cout << endl;
    //ll pos = 0;
    //ob[n + 1] = LONG_MAX;
    //for(int i = 1; i <= n + 1; ++i) {
        //if(q.empty()) q.push(ob[i]);
        //else {
            //q.push(ob[i]);
            //ll l = q.front(), r;
            ////cout << l << endl;
            //if(ob[i] - l < d - 1) continue;
            //while(!q.empty()) {
                //if(q.front() - l > d - 2) break;
                //r = q.front();
                //q.pop();
            //}
            ////cout << "***" << i << " " << l << " " << r << " " << pos << endl; 
            //if(l - pos < s) { cout << "IMPOSSIBLE" << endl; return 0; }
            //v.push_back(make_pair('r', l - pos - 1));
            //v.push_back(make_pair('j', r - l + 2));
            //pos = r + 1;
        //}
    //}

    //v.push_back(make_pair('r', m - pos));

    //for(auto a : v) {
        //cout << (a.first == 'r' ? "RUN" : "JUMP") << " " << a.second << endl;
    //}


/*}*/
