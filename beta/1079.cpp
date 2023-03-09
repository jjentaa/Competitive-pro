#include <bits/stdc++.h>

using namespace std;
int N, K;
int dp[100002];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    dp[0]=1;
    int pivot=0;
    for(int i=1; i<=N; i++){
        if(i<=K){
            pivot+=dp[i-1];
            dp[i]=pivot;
        }
        else{
            pivot+=dp[i-1]-dp[i-K-1];
            dp[i]=pivot;
        }
        dp[i]%=2009;
    }

    cout << dp[N];

    return 0;
}