#include <bits/stdc++.h>
using namespace std;
int M, N, ans;
queue<pair<int,int>> g;
bool visitt[2001][2001];
int row[]={1, 1, 1, 0, 0, -1, -1, -1};
int col[]={1, 0, -1, 1, -1, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> M >> N;
    for(int i=1; i<=M; i++){
        string sth;
        cin >> sth;
        for(int j=0; j<sth.size(); j++){
            if(sth[j]=='0') visitt[i][j+1]=true;
        }
    }
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            if(visitt[i][j]) continue;
            ans++;
            visitt[i][j]=true;
            g.push({i, j});
            while(!g.empty()){
                int x=g.front().first, y=g.front().second;
                g.pop();
                visitt[x][y]=true;
                for(int u=0; u<8; u++){
                    if(x+row[u]<1 || y+col[u]<1 || x+row[u]>M || y+col[u]>N || visitt[x+row[u]][y+col[u]]) continue;
                    visitt[x+row[u]][y+col[u]]=true;
                    g.push({x+row[u], y+col[u]});
                }
            }
        }
    }
    cout << ans;
    return 0;
}