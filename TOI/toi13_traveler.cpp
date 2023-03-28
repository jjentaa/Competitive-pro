#include <bits/stdc++.h>

using namespace std;
const int mxN=1e4;
int n, m, x, y, z, u, v, w;
vector<pair<int, int>> adj[mxN+1];
int dis1[mxN+1], dis2[mxN+1];

struct Data{
    int v;
    long long w;
    bool operator < (const Data &d2) const{
        return d2.w<w;
    }
};

priority_queue<Data> pq;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> x >> y >> z;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //from start
    for(int i=0; i<n; i++) dis1[i]=INT_MAX;
    dis1[x]=0;
    pq.push({x, 0LL});
    while(!pq.empty()){
        int u=pq.top().v;
        pq.pop();
        for(auto [v, w]:adj[u]){
            if(dis1[u]+w<dis1[v]){
                dis1[v]=dis1[u]+w;
                pq.push({v, dis1[v]});
            }
        }
    }

    //from desnitation
    for(int i=0; i<n; i++) dis2[i]=INT_MAX;
    dis2[y]=0;
    pq.push({y, 0LL});
    while(!pq.empty()){
        int u=pq.top().v;
        pq.pop();
        for(auto [v, w]:adj[u]){
            if(dis2[u]+w<dis2[v]){
                dis2[v]=dis2[u]+w;
                pq.push({v, dis2[v]});
            }
        }
    }

    int final=INT_MAX, left=INT_MAX, dis;
    for(int i=0; i<n; i++){
        if(dis1[i]<=z){
            if(dis2[i]<left){
                left=dis2[i];
                dis=dis1[i];
                final=i;
            }
            //left=0
            else if(dis2[i]==left) final=min(final, i);
        }
    }

    cout << final << " " << dis << " " << left;

    return 0;
}