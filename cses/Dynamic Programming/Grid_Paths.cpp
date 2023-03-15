#include <bits/stdc++.h>

using namespace std;
int n;
int grid[1002][1002];
long long dp[1002][1002];
const int mod=1e9+7;
string c;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c;
        for(int j=0; j<n; j++){
            if(c[j]=='*') grid[i][j+1]=1;
        }
    }

    if(grid[1][1]==1) dp[1][1]=0;
    else dp[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!grid[i][j]){
                if(!grid[i-1][j]) dp[i][j]+=dp[i-1][j];
                if(!grid[i][j-1]) dp[i][j]+=dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }

    cout << dp[n][n];

    return 0;
}