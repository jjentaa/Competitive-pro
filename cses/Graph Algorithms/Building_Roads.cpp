#include <bits/stdc++.h>

using namespace std;
const int mxN=1e5+1;
vector<int> adj[mxN], ans;
int visitt[mxN];
int n, m, u, v;

void dfs(int u){
    visitt[u]=1;
    for(int v: adj[u]){
        if(!visitt[v]){
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(!visitt[i]){
            ans.push_back(i);
            dfs(i);
        }
    }

    cout << ans.size()-1 << "\n";
    for(int i=1; i<ans.size(); i++){
        cout << ans[i-1] << " " << ans[i] << "\n";
    }

    return 0;
}