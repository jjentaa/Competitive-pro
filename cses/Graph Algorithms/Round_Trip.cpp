#include <bits/stdc++.h>

using namespace std;
const int mxN=1e5+1;
int n, m;
vector<int> g[mxN], ans;
int visitt[mxN], dis[mxN];

void dfs(int u, int pa){
    visitt[u]=1;
    dis[u]=pa;
    for(auto v:g[u]){
        if(visitt[v]==2||v==pa) continue;
        if(visitt[v]==1){
            for (int s = u; s != v; s = dis[s]) ans.push_back(s);
            reverse(ans.begin(), ans.end());
            ans.push_back(v);
            cout << ans.size()+1 << "\n";
            for (int x : ans) cout << x  << " ";
            cout << *ans.begin();
            exit(0);
        }
        dfs(v, u);
    }
    visitt[u]=2;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!visitt[i]) dfs(i, -1);
    }
    cout << "IMPOSSIBLE";

    return 0;
}