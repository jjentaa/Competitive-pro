#include <bits/stdc++.h>

using namespace std;

struct Data{
    int u, v;
    long long w;

    bool operator < (const Data &rhs) const{
        return w<rhs.w;
    }
};

int n, m, root[200001];
long long ans;
priority_queue<Data> pq;

int findroot(int x){
    if(root[x]==x) return x;
    return root[x]=findroot(root[x]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    iota(root+1, root+n+1, 1); //pa[i]=i; i:1-n
    int u, v;
    long long w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        pq.push({u, v, w-1});
    }

    while(!pq.empty()){
        int u=pq.top().u, v=pq.top().v;
        long long w=pq.top().w;
        pq.pop();
        if(findroot(u)!=findroot(v)){
            ans+=w;
            root[findroot(v)]=findroot(u);
        }
    }

    cout << ans;

    return 0;
}