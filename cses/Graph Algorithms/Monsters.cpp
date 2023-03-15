#include <bits/stdc++.h>

using namespace std;
int visitt[1001][1001], dis[1001][1001], dis2[1001][1001];
char path[1001][1001], g[1001][1001];
int row[]={0, 0, 1, -1};
int col[]={1, -1, 0, 0};
char dir[]={'R', 'L', 'D', 'U'};
int n, m, startx, starty, endx, endy;
queue<pair<int, int> > q;

void displayPath(int x, int y){
    cout << "YES" << "\n" << dis2[x][y] << "\n";
    string ans="";
    int nowx=x, nowy=y;
    for(int t=0; t<dis2[x][y]; t++){
        ans+=path[nowx][nowy];
        if(path[nowx][nowy]=='D') nowx--;
        else if(path[nowx][nowy]=='U') nowx++;
        else if(path[nowx][nowy]=='R') nowy--;
        else if(path[nowx][nowy]=='L') nowy++;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    string sth;
    for(int i=1; i<=n; i++){
        cin >> sth;
        for(int j=1; j<=m; j++){
            g[i][j]=sth[j-1];
            if(sth[j-1]=='#') visitt[i][j]=1;
            else if(sth[j-1]=='A') startx=i, starty=j;
            else if(sth[j-1]=='M'){
                visitt[i][j]=1;
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int newX=x+row[d], newY=y+col[d];
            if(newX<1 || newY<1 || newX>n || newY>m || visitt[newX][newY]) continue;
            dis[newX][newY]=dis[x][y]+1;
            visitt[newX][newY]=1;
            q.push({newX, newY});
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!visitt[i][j]) dis[i][j]=INT_MAX;
            if(g[i][j]=='#') visitt[i][j]=1;
            else visitt[i][j]=0;
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
            if(dis2[x][y]+1<dis[newX][newY]){
                path[newX][newY]=dir[d];
                dis2[newX][newY]=dis2[x][y]+1;
                visitt[newX][newY]=1;
                q.push({newX, newY});
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(g[i][1]!='#' && g[i][1]!='M' && visitt[i][1]){
            displayPath(i, 1);
            return 0;
        }
        else if(g[i][m]!='#' && g[i][m]!='M' && visitt[i][m]){
            displayPath(i, m);
            return 0;
        }
    }

    for(int i=1; i<=m; i++){
        if(g[1][i]!='#' && g[1][i]!='M' && visitt[1][i]){
            displayPath(1, i);
            return 0;
        }
        else if(g[n][i]!='#' && g[n][i]!='M' && visitt[n][i]){
            displayPath(n, i);
            return 0;
        }
    }

    cout << "NO";

    return 0;
}