#include <bits/stdc++.h>

using namespace std;
int m, n, startx, starty, endx, endy;
int row[]={0, 0, 1, -1};
int col[]={1, -1, 0, 0};
char dir[]={'R', 'L', 'D', 'U'};
char g[1001][1001], path[1001][1001];
int visitt[1001][1001], dis[1001][1001];
queue<pair<int, int> > q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> g[i][j];
            if(g[i][j]=='A') startx=i, starty=j;
            if(g[i][j]=='B') endx=i, endy=j;
            if(g[i][j]=='#') visitt[i][j]=1;
        }
    }

    visitt[startx][starty]=1;
    q.push({startx, starty});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        visitt[x][y]=1;
        for(int d=0; d<4; d++){
            int newX=x+row[d], newY=y+col[d];
            if(newX<1 || newY<1 || newX>n || newY>m || visitt[newX][newY]) continue;
            path[newX][newY]=dir[d];
            dis[newX][newY]=dis[x][y]+1;
            visitt[newX][newY]=1;
            q.push({newX, newY});
        }
    }
    
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         cout << path[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(!visitt[endx][endy]){
        cout <<"NO";
        return 0;
    }

    cout << "YES" << "\n" << dis[endx][endy] << "\n";

    string ans="";
    int nowx=endx, nowy=endy;
    while(dis[endx][endy]--){
        ans+=path[nowx][nowy];
        if(path[nowx][nowy]=='D') nowx--;
        else if(path[nowx][nowy]=='U') nowx++;
        else if(path[nowx][nowy]=='R') nowy--;
        else if(path[nowx][nowy]=='L') nowy++;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}