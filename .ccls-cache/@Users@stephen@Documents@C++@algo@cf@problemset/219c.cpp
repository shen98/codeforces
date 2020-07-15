#include <iostream>
#include <string>
using namespace std;

int n, k;
string s;

int main() {
    cin >> n >> k;

    cin >> s;

    int sz = s.size();

    if(k == 2) {
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < sz; ++i) {
            if(s[i] != 'A') {
                if(i % 2 == 1) cnt1++;
                else cnt2++;
            }
            if(s[i] != 'B') {
                if(i % 2 == 0) cnt1++;
                else cnt2++;
            }
        }

        //cout << 1 << endl;
        bool f = (cnt1 <= cnt2);
        cout << (f ? cnt1 : cnt2) << endl;
        for(int i = 0; i < sz; ++i) {
            //cout << "***" << f << endl;
            if(f) {
                if(i % 2 == 0) cout << "B";
                else cout << "A";
            } else {
                if(i % 2 == 0) cout << "A";
                else cout << "B";
            }
        }
        cout << endl;
    } else {
        //cout << 1 << endl;
        int cnt = 0;
    for(int i = 1; i < s.size() - 1; ++i) {
        if(s[i] == s[i - 1] && s[i] == s[i + 1]) {
            int j = 0;
            for(; j <= 25; ++j) {
                if(s[i - 1] == 'A' + j || s[i + 1] == 'A' + j) continue;
                else break;
            }
            s[i] = 'A' + j;
            cnt++;
        }
    }
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == s[i - 1] || s[i] == s[i + 1]) {
                //cout << 2 << endl;
                int j = 0;
                for(; j <= k; ++j) {
                    if(s[i - 1] == 'A' + j || s[i + 1] == 'A' + j) continue;
                    else break;
                }
                s[i] = 'A' + j;
                cnt++;
            }
        }
        cout << cnt << endl;
        cout << s << endl;
    }
/*    int cnt = 0;*/
    //for(int i = 1; i < s.size() - 1; ++i) {
        //if(s[i] == s[i - 1] && s[i] == s[i + 1]) {
            //int j = 0;
            //for(; j <= 25; ++j) {
                //if(s[i - 1] == 'A' + j || s[i + 1] == 'A' + j) continue;
                //else break;
            //}
            //s[i] = 'A' + j;
            //cnt++;
        //}
    //}

    ////cout << "***" << cnt << " " << s << endl;
    //for(int i = 1; i < s.size(); ++i) {
        //if(s[i] == s[i - 1]) {
            //int j = 0;
            //for(; j <= 25; ++j) {
                //if(s[i - 1] == 'A' + j || s[i + 1] == 'A' + j) continue;
                //else break;
            //}
            //s[i] = 'A' + j;
            //cnt++;
        //}
    //}

    //cout << cnt << endl;
    /*cout << s << endl;*/
}
