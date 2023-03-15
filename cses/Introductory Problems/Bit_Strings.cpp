#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
const int mxN=1e6+1;
int dp[mxN], n;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    dp[0]=1;
    for(int i=1; i<=n; i++){
        dp[i]=(dp[i-1]*2)%mod;
    }

    cout << dp[n];

    return 0;
}