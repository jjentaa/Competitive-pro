#include <bits/stdc++.h>

using namespace std;
int m, n, rs, cs, re, ce, counter, mindis=2e9+7;
int g[151][151], disS[151][151], disE[151][151];
int row[]={-1, 1, 0, 0};
int col[]={0, 0, -1, 1};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n >> rs >> cs >> re >> ce;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> g[i][j];
        }
    }

    queue<pair<int, int>> q;
    disS[rs][cs]=1;
    q.push({rs, cs});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();

        for(int d=0; d<4; d++){
            int newX=x+row[d], newY=y+col[d];
            if(newX<1 || newY<1 || newX>m || newY>n || disS[newX][newY]) continue;
            if(g[newX][newY]) q.push({newX, newY});
            disS[newX][newY]=disS[x][y]+1;
        }
    }

    q.push({re, ce});
    disE[re][ce]=1;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();

        for(int d=0; d<4; d++){
            int newX=x+row[d], newY=y+col[d];
            if(newX<1 || newY<1 || newX>m || newY>n || disE[newX][newY]) continue;
            if(g[newX][newY]) q.push({newX, newY});
            disE[newX][newY]=disE[x][y]+1;
            if(disS[newX][newY]!=0&&disE[newX][newY]!=0){
                counter++;
                mindis=min(mindis, disS[newX][newY]+disE[newX][newY]-1);
            }
        }
    }

    cout << counter << "\n" << mindis;

    return 0;
}