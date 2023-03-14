#include <bits/stdc++.h>

using namespace std;

struct Path{
    int v;
    long long w;
    Path() { }
    Path(int v, long long w): v(v), w(w) {}
    bool operator < (const Path &rhs) const{
        return w>rhs.w;
    }
};

int n, m;
vector<pair<int, int> > g[100001];
long long dis[100001];
priority_queue<Path> pq;

void dijkstra(){
    fill(dis, dis+100001, LLONG_MAX);
    dis[1]=0;

    pq.push(Path(1, 0LL));
    
    while(!pq.empty()){
        int u=pq.top().v;
        int w=pq.top().w;
        pq.pop();
        if(dis[u]<w) continue; //check dis parent
        for(auto edge:g[u]){
            int v=edge.first;
            long long w=edge.second;

            if(dis[v]<=dis[u]+w) continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push(Path(v, dis[v]));
            }
        }
    }
}

int u, v;
long long w;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        //g[v].push_back(make_pair(u, w));
    }

    dijkstra();

    for(int i=1; i<=n; i++){
        cout << dis[i] << " ";
    }

    return 0;
}
