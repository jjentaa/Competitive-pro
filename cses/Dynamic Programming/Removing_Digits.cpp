#include <bits/stdc++.h>

using namespace std;
int dp[1000001], n;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    fill(dp+1, dp+1000001, INT_MAX);
    for(int i=1; i<=n; i++){
        int num=i;
        while(num>0){
            if(num%10){
                dp[i] = min(dp[i], dp[i-(num%10)]+1);
            }
            num/=10;
        }
    }

    cout << dp[n];

    return 0;
}