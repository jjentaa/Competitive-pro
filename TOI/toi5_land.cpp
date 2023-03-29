#include <bits/stdc++.h>

using namespace std;
int m, n;
double g[5][5];
bool visitt[5][5];
int row[]={-1, -1, -1, 1, 1, 1, 0, 0};
int col[]={-1, 0, 1, -1, 0, 1, -1, 1};
double minn=DBL_MAX;

void floodfill(int step, double cost){
    if(step==m*n){
        minn=min(minn, cost);
        return ;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(visitt[i][j]) continue;
            visitt[i][j]=true;
            for(int d=0; d<8; d++){
                g[i+row[d]][j+col[d]]+=g[i][j]*0.1;
            }
            floodfill(step+1, cost+g[i][j]);
            visitt[i][j]=false;
            for(int d=0; d<8; d++){
                g[i+row[d]][j+col[d]]-=g[i][j]*0.1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> g[i][j];
        }
    }

    floodfill(0, 0);

    printf("%.2lf", minn);

    return 0;
}