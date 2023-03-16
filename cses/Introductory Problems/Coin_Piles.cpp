#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    long long a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        // case (2, 1) swapping case always 2, 1 case always 1,2
        if((a+b)%3 || 2*a<b || 2*b<a) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }

    return 0;
}