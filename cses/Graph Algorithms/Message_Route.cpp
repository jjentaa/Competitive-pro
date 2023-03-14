#include <bits/stdc++.h>

using namespace std;
vector<int> adj[200001];
int dis[200002], visitt[200002], path[200002];
int n, m;

void bfs(int start){
    queue<int> q;
    q.push(start);
    visitt[start]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(!visitt[v]){
                visitt[v]=1;
                dis[v]=dis[u]+1;
                path[v]=u;
                q.push(v);
            }
        }
    }
}

void displayPath(int v){
    if(path[v]==0){
        cout << v << " ";
        return ;
    }
    displayPath(path[v]);
    cout << v << " ";
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);

    if(!visitt[n]){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << dis[n]+1 << "\n";
    displayPath(n);

    return 0;
}