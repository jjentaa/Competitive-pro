#include <bits/stdc++.h>

using namespace std;
long long t, row, col, s, ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while(t--){
        cin >> row >> col;
        s=max(row, col);
        if(s%2){
            if(s==row) ans=((s-1)*(s-1))+col;
            else ans=(s*s)-(row-1);
        }
        else{
            if(s==col) ans=((s-1)*(s-1))+row;
            else ans=(s*s)-(col-1);
        }
        cout << ans << "\n";
    }

    return 0;
}