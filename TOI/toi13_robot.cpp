#include <bits/stdc++.h>

using namespace std;
int n, m;
struct Data{
    int x, y, step;
};
char g[2001][2001];
int visitt[2001][2001];
int row[]={1, -1, 0, 0};
int col[]={0, 0, -1, 1};
string sth;
queue<Data> q;
int counter, dis;
int isValid(int x, int y){
    if(x<1 || y<1 || x>n || y>m) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> sth;
        for(int j=1; j<=m; j++){
            g[i][j]=sth[j-1];
            if(g[i][j]=='X'){
                visitt[i][j]=1;
                q.push({i, j, 0});
            }
            if(g[i][j]=='W') visitt[i][j]=1;
        }
    }

    while(!q.empty()){
        Data temp=q.front();
        q.pop();
        for(int d=0; d<4; d++){
            int newX=temp.x+row[d], newY=temp.y+col[d];
            if(!isValid(newX, newY)) continue;
            if(visitt[newX][newY]) continue;
            if(g[newX][newY]=='A'){
                visitt[newX][newY]=1;
                counter++;
                dis+=(temp.step+1)*2;
                q.push({newX, newY, temp.step+1});
            }
            else{
                visitt[newX][newY]=1;
                q.push({newX, newY, temp.step+1});
            }
        }
    }

    cout << counter << " " << dis;

    return 0;
}