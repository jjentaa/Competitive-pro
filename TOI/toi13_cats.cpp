#include <bits/stdc++.h>

using namespace std;
int n, ans, pre, now;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> now;
        if(pre==0) pre=now;
        else if(pre<now){
            ans=max(ans, pre);
            pre=now;
        }
        else if(pre==now) pre=0;
        else if(pre>now) ans=max(ans, now);
    }

    cout << ans;

    return 0;
}