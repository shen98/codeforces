#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s.size() <= 2) { cout << 0 << endl; continue; }
        vector<int> vec1(s.size() + 1);
        vector<int> vec0(s.size() + 1);
        for(int i = 0; i < s.size(); ++i) {
            vec0[i + 1] = vec0[i];
            vec1[i + 1] = vec1[i];
            if(s[i] == '0') vec0[i + 1]++;
            else vec1[i + 1]++;
        }

/*        for(auto a : vec1) cout << a << " ";*/
        //cout << endl;
        //for(auto a : vec0) cout << a << " ";
        /*cout << endl;*/
        int num1 = 0, num0 = 0, ans = INT_MAX;
        for(int i = s.size() - 1; i >= 1; i--) {
            if(s[i] == '1') num1++;
            else num0++;
            //cout << "***" << num0 << " " << num1 << " " << i - vec1[i] + (int)s.size() - num0 - i << " " << i - vec0[i] +(int)s.size() - num1 - i <<  endl;
            ans = min(min(i - vec1[i] + (int)s.size() - num0 - i,
                        i - vec0[i] + (int)s.size() - num1 - i), ans);
        }

        ans = min(min(vec1.back(), vec0.back()), ans);
        cout << ans << endl;
    }
    return 0;
}
