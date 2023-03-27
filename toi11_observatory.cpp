#include <bits/stdc++.h>

using namespace std;
int m, n, k, ans=INT_MIN;
int arr[2001][2001];
int sql[2001][2001], sqr[2001][2001];
int tril[2001][2001], trir[2001][2001];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n >> k;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            sql[i][j]=sql[i-1][j]+sql[i][j-1]-sql[i-1][j-1]+arr[i][j];
            tril[i][j]=tril[i-1][j-1]+sql[i][j]-sql[i-1][j];
        }
        for(int j=n; j>=1; j--){
            sqr[i][j]=sqr[i][j+1]+sqr[i - 1][j] - sqr[i-1][j+1]+arr[i][j];
            trir[i][j]=sqr[i][j]-sqr[i-1][j]+trir[i-1][j+1];
        }
    }

    for(int i=k; i<=m; i++){
        for(int j=k; j<=n; j++){
            ans=max(ans, tril[i][j]-tril[i-k][j-k]-sql[i][j-k]+sql[i-k][j-k]);
        }
        for(int j=n-k+1; j>=1; j--){
            ans=max(ans, trir[i][j]-trir[i-k][j+k]-sqr[i][j+k]+sqr[i-k][j+k]);
        }
    }

    cout << ans;

    return 0;
}