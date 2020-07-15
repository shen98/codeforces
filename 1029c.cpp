#include <iostream>
using namespace std;

const int N = 3e5 + 5;
int n, id, Min= INT_MAX;
int l[N], r[N];
int prl[N], prr[N], sul[N], sur[N];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];

    }

    prl[1] = sul[n + 1] = 0;
    prr[1] = sur[n + 1] = INT_MAX;

    for(int i = 1; i <= n; ++i) {
        prl[i + 1] = max(prl[i], l[i]);
        prr[i + 1] = min(prr[i], r[i]);
    }

/*    for(int i = 1; i <= n + 1; ++i) { cout << prl[i] << " "; }*/
    //cout << endl;
    //for(int i = 1; i <= n + 1; ++i) { cout << prr[i] << " "; }
    /*cout << endl;*/
    for(int i = n; i >= 1; --i) {
        sul[i] = max(sul[i + 1], l[i]);
        sur[i] = min(sur[i + 1], r[i]);
    }
/*    for(int i = 1; i <= n + 1; ++i) { cout << sul[i] << " "; }*/
    //cout << endl;
    //for(int i = 1; i <= n + 1; ++i) { cout << sur[i] << " "; }
    /*cout << endl;*/
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, min(prr[i], sur[i + 1]) - max(prl[i], sul[i + 1]));
    }

    cout << ans << endl;
    //cout << (an,s < 0 ? ans : ans) << endl;
/*    int ml = 0, mr = INT_MAX;*/
    //for(int i = 1; i <= n; ++i) {
        ////cout << l[i] << " " << r[i] << endl;
        //if(i == id) continue;
        //ml = max(ml, l[i]);
        //mr = min(mr, r[i]);
    //}

    /*cout << (mr - ml < 0 ? 0 : mr - ml) << endl;*/
}
