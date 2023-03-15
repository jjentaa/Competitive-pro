#include <bits/stdc++.h>

using namespace std;
int n, ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while(n>0){
        n/=5; //factor
        ans+=n;
    }
    cout << ans;

    return 0;
}