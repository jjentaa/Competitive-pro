#include <bits/stdc++.h>

using namespace std;
int m, n, q;
long long dis[501][501];
const long long INF = 0x3f3f3f3f3f3f3f3f;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> q;
    int u, v;
    long long w;
    for(int i=1; i<=m; i++){
        cin >> u >> v >> w;
        dis[u][v]=min(dis[u][v], w);
        dis[v][u]=min(dis[v][u], w);
    }

    for(int a=1; a<=n; a++) dis[a][a]=0;
    for(int k=1; k<=500; k++){
        for(int i=1; i<=500; i++){
            for(int j=1; j<=500; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    int s, e;
    while(q--){
        cin >> s >> e;
        if(dis[s][e]==INF) cout << -1 << "\n";
        else cout << dis[s][e] << "\n";
    }

    return 0;
}