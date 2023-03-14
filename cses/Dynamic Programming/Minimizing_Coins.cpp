#include <bits/stdc++.h>

using namespace std;

int coins[101];
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    fill(dp+1, dp+x+2, INT_MAX);
    dp[0]=0;

    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(coins[j] <= i){
                int res=dp[i-coins[j]];
                if(res!=INT_MAX && res+1<dp[i]) dp[i]=res+1;
            }
        }
    }

    if(dp[x]==INT_MAX) cout << -1;
    else cout << dp[x];
	return 0;
}

