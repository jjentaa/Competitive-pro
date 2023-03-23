#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long m, n, ans;
    int mover=20;
    while(mover--){
        cin >> m >> n;
        ans=(4*n-m)/2;
        if(ans<0 || ans>n) cout<< 0 << "\n";
        else cout << ans+1 << "\n"; //include 0
    }

    return 0;
}