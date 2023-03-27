#include <bits/stdc++.h>

using namespace std;
const int mxN=1e5+1;
int n, m;
vector<int> g[mxN];
bool isPossible, visitt[mxN], teamm[mxN];

void dfs(int u, int p=0){
    for(int v:g[u]){
        if(v!=p){
            if(!visitt[v]){
                teamm[v]=!teamm[u];
                visitt[v]=true;
                dfs(v, u);
            }
            else{
                if(teamm[u]==teamm[v]) isPossible=false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    isPossible=true;
    for(int i=1; i<=n; i++){
        if(!visitt[i]){
            visitt[i]=true;
            dfs(i);
        }
    }

    if(!isPossible) cout << "IMPOSSIBLE";
    else{
        for(int i=1; i<=n; i++){
            if(teamm[i]) cout << 2 << " ";
            else cout << 1 << " ";
        }
    }

    return 0;
}