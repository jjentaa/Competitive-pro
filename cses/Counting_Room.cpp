#include <bits/stdc++.h>

using namespace std;
int n, m;
int g[1001][1001];
int visitt[1001][1001];

int isValid(int x, int y){
    if(x<1 || y<1 || x>n || y>m || visitt[x][y] || g[x][y]) return 0;
    return 1;
}

int floodfill(int x, int y){
    visitt[x][y]=1;
    int row[] = {0, -1, 1, 0};
    int col[] = {1, 0, 0, -1};
    for(int u=0; u<4; u++){
        if(isValid(x+row[u], y+col[u])) floodfill(x+row[u], y+col[u]);
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin >> c;
            if(c=='#') g[i][j]=1;
            else g[i][j]=0;
        }
    }

    int counter=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(isValid(i, j)){
                counter++;
                floodfill(i, j);
            }
        }
    }
    cout << counter;

    return 0;
}