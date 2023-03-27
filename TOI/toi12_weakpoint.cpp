#include <bits/stdc++.h>

using namespace std;
const int mxN=5e5;
int u, v;
int n, m, visitt[mxN+1], minn, maxx=-1;
vector<int> adj[mxN+1];

int dfs(int u, int pa){
    visitt[u]=1;
    bool isCycle=false;
    int counter=0;
    for(auto v: adj[u]){
        if(v==m) isCycle=true;
        if(visitt[v]) continue;
        int temp=dfs(v, u);
        if(temp==0) isCycle=true;
        counter+=temp;
    }

    if(u!=m){
        if(counter>maxx){
            maxx=counter; //choose more node
            minn=u;
        }
        else if(counter==maxx) minn=min(u, minn); //less number
    }

    if(isCycle) return 0; // calc first

    return counter+1;

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(m, 0);
    cout << minn << "\n" << maxx;

    return 0;
}