#include <bits/stdc++.h>

using namespace std;
int x, target, c;
int dp[1000001];
const int mod=1e9+7;
vector<int> coins;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> x >> target;
    for(int i=0; i<x; i++){
        cin >> c;
        coins.push_back(c);
    }

    dp[0]=1; // no pick any coin 1 way
    for(int i=0; i<=target; i++){
        for(int j=0; j<x; j++){
                if(i+coins[j]<=target){
                    dp[i+coins[j]]=(dp[i+coins[j]]+dp[i])%mod;
                }
            }
        // if(dp[i]!=0){
        //     for(int j=0; j<x; j++){
        //         if(i+coins[j]<=target){
        //             dp[i+coins[j]]=(dp[i+coins[j]]+dp[i])%mod;
        //         }
        //     }
        // }
    }

    cout << dp[target];

    return 0;
}