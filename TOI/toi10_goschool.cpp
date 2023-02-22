#include <bits/stdc++.h>

using namespace std;
int arr[52][52];
long long dp[52][52];
int m, n, d, x, y;
long long solve(int row, int col){
    if(arr[row][col]) return 0;
    if(dp[row][col]) return dp[row][col];
    if(row<=0 || col<=0) return 0;
    return dp[row][col]=solve(row-1, col)+solve(row, col-1);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    cin >> d;
    for(int i=0; i<d; i++){
        cin >> y >> x;
        arr[x][y]=1;
    }

    //display arr
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    dp[1][1]=1;
    cout << solve(n, m);

    return 0;
}