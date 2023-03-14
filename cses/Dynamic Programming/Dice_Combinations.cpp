#include <bits/stdc++.h>

using namespace std;
const int mod=1e9+7;
int N;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dp[0]=1;
    for(int i=1; i<=N; i++){
        for(int j = 1; j <= 6 && i-j >= 0; j++){
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }

    cout << dp[N];

    return 0;
}