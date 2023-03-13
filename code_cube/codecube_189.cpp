#include <bits/stdc++.h>

using namespace std;
struct Edge{
    long long v;
    long long w;
    Edge() { }
    Edge(long long v, long long w): v(v), w(w) {}
};

struct Path{
    long long v, w, mx;
    Path() {}
    Path(long long v, long long w, long long mx): v(v), w(w), mx(mx) {}
    bool operator < (const Path &rhs) const{
        //the max path if delete the max dis in path
        if(rhs.w == w) return w-mx > rhs.w-rhs.mx;
        return w > rhs.w;
    }
};

vector<Edge> g[100001];
priority_queue<Path> pq;
long long total;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M, S, T;
    cin >> N >> M;
    cin >> S >> T;
    for(int i=0; i<M; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
        total += w;
    }

    pq.push(Path(S, 0, INT_MIN));
    long long result=LONG_MAX;
    vector<long long int> dis(N, 1e12);
    while(!pq.empty()){
        long long v=pq.top().v, w=pq.top().w, mx=pq.top().mx;
        pq.pop();
        if(dis[v]<=w-mx) continue; // the short path - max in path is least
        dis[v]=w-mx;

        if(v==T){
            result=min(result, w-mx);
            continue;
        }

        for(Edge e:g[v]){
            // end ,dis ,mx dis in path
            pq.push(Path(e.v, e.w+w, max(e.w, mx)));
        }
    }

    cout << total-result;

    return 0;
}