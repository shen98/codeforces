#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    vector<int> v;
    char a = s[0];
    int num = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i] == a) num++;
        else {
            v.push_back(num);
            a = s[i];
            num = 1;
        }
    }
    if(num != 0) v.push_back(num);


/*    cout << endl;*/
    //for(auto d : v) cout << d << " ";
    /*cout << endl;*/
    if(s[0] == 'S') v.erase(v.begin());
    int ans = -1, t = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(i % 2 == 0) { ans = max(ans, v[i]); t += v[i]; }
        else {
            if(v[i] == 1 && i + 1 < v.size()) ans = max(ans, v[i - 1] + v[i + 1]);
        }
    }

    if(ans == -1) cout << 0 << endl;
    else cout << (t > ans ? ans + 1 : ans) << endl;
    return 0;
}
