#include <bits/stdc++.h>

using namespace std;
int n, m;
long long u, v, w, s, d, p, ans;
vector<array<long long, 3>> adj;
long long parent[2502];

long long find(long long x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj.push_back({w, u, v}); //w-1=หักไกด์
    }

    cin >> s >> d >> p;
    sort(adj.begin(), adj.end());
    reverse(adj.begin(), adj.end());//descending
    iota(parent+1, parent+n+1, 1);

    for(auto edge: adj){
        long long a=find(edge[1]), b=find(edge[2]);
        if(a!=b){
            parent[b]=a;
            ans=edge[0];
            if(find(s)==find(d)){
                cout << ceil(p/(float) (ans-1));
                return 0;
            }
        }
    }

    return 0;
}