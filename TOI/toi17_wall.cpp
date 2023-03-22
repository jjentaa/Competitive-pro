#include <bits/stdc++.h>

using namespace std;
int r, c, ans=0;
char g[1001][1001];
bool visitt1[1001][1001], visitt2[1001][1001];
int row[]={-1, 1, 0, 0};
int col[]={0, 0, -1, 1};
queue<pair<int, int>> q;
int isValid(int x, int y){
    if(x<1 || y<1 || x>r || y>c) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> r >> c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> g[i][j];
            // if(g[i][j]=='X') visitt1[i][j]=1; 
            if(i==1 || j==1 || i==r || j==c){
                q.push({i, j});
                visitt1[i][j]=true;
                //visitt2[i][j]=1;
            }
        }
    }

    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int newX=x+row[d], newY=y+col[d];
            if(!isValid(newX, newY)) continue;
            if(g[newX][newY]=='X' || visitt1[newX][newY]) continue;
            q.push({newX, newY});
            visitt1[newX][newY]=true;
        }
    }

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(visitt2[i][j] || g[i][j]=='.') continue;
            visitt2[i][j]=1;
            q.push({i,j});
            int counter=0;
            while(!q.empty()){ //only house
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int d=0; d<4; d++){
                    int newX=x+row[d], newY=y+col[d];
                    if(!isValid(newX, newY)) continue;
                    if(visitt2[newX][newY]) continue;
                    if(g[newX][newY]=='.'&&visitt1[newX][newY]) counter++; // ติดน้ำ
                    if(g[newX][newY]=='X'){ // บ้านที่ติดกัน
                        q.push({newX, newY});
                        visitt2[newX][newY]=true;
                    }
                }
            }
            ans=max(ans, counter);
        }
    }

    cout << ans;

    return 0;
}