#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, numA = 0, numB = 0;
        cin >> n >> x;
        vector<int> vec(n);
        for(int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if(a % 2 == 1) numA++;
            else numB++;
        }
        
        
        if(numA == 0) cout << "No" << endl;
        else if(numB == 0) {
            if(x % 2 == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if(x == n) {
            if(numA % 2 == 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
        else cout << "Yes" << endl;

    }
    return 0;
}
