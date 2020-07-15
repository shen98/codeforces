#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, c;

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> s >> c;
        
        for(int i = 0; i < s.size(); ++i) {
            int idx = i;
            for(int j = i + 1; j < s.size(); ++j) {
                if(s[j] <= s[idx]) idx = j;
            }
            if(s[idx] != s[i]) {
                swap(s[idx], s[i]);
                break;
            }
        }
        if(s < c) cout << s << endl;
        else cout << "---\n";
    }
}
