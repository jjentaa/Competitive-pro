#include <bits/stdc++.h>

using namespace std;

struct Data{
    int node, r, c;
};

bool visitt[40002];
//bitset<40002> visitt;
vector<Data> adj[40002];
int ans[402][402];
int m, n;
queue<Data> q;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<(m*n)-1; i++){
        int u, v;
        char d;
        cin >> u >> d >> v;
        if(d=='U'){
            adj[u].push_back({v, 1, 0});
            adj[v].push_back({u, -1, 0});
        }
        if(d=='L'){
            adj[u].push_back({v, 0, 1});
            adj[v].push_back({u, 0, -1});
        }
    }
    int xminn=401, xmaxx=0, yminn=401, ymaxx=0;
    q.push({0, n, m});
    visitt[0]=true;
    while(!q.empty()){
        int node=q.front().node, r=q.front().r, c=q.front().c;
        q.pop();
        ans[r][c]=node;
        xminn=min(xminn, r);
        xmaxx=max(xmaxx, r);
        yminn=min(yminn, c);
        ymaxx=max(ymaxx, c);
        //visitt[node]=true;
        for(auto e: adj[node]){
            if(!visitt[e.node]){
                q.push({e.node, r+e.r, c+e.c});
                visitt[e.node]=true;
            }
        }
    }

    for(int i=xminn; i<=xmaxx; i++){
        for(int j=yminn; j<=ymaxx; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}