#include <bits/stdc++.h>

using namespace std;
const int mxN=1e5+1;
int n, m;
long long ans;

vector<pair<long long, pair<int, int>>> adj;
int pa[mxN+1];

int find(int a){
    if(pa[a]==a) return a;
    return pa[a]=find(pa[a]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    int u, v;
    long long w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    sort(adj.begin(), adj.end());

    for(int i = 1;i<=mxN;i++)pa[i] = i; 

    for(auto edge:adj){
        long long w=edge.first;
        int u=edge.second.first, v=edge.second.second;
        if(find(u)!=find(v)){
            ans+=w;
            pa[find(u)] = find(v);
            n--;
        }
    }

    if(n==1) cout << ans;
    else cout << "IMPOSSIBLE";

    return 0;
}