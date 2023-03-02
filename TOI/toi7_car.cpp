#include <bits/stdc++.h>

using namespace std;
int g[101][41];
int m, n, t;
string ans;

int solve(int x, int y){
    if(y<1 || y>m) return 0;
    if(g[x][y]) return 0;
    if(x==t && g[x][y]==0) return 1;
    //1
    if(solve(x+1, y-1)){
        ans+="1";
        return 1;
    }
    //2
    if(solve(x+1, y+1)){
        ans+="2";
        return 1;
    }
    //3
    if(solve(x+1, y)){
        ans+="3";
        return 1;
    }


    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n >> t;
    for(int i=1; i<=t; i++){
        for(int j=1; j<=m; j++){
            cin >> g[i][j];
        }
    }

    solve(0, n);
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << "\n";

    return 0;
}