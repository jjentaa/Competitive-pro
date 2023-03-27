#include <bits/stdc++.h>

using namespace std;
int n, m, q, a, b;
long long p;
long long items[501];
pair<long long, int> g[501][501];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;

    for(int i=1; i<=n; i++) cin >> items[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            g[i][j].first=items[i]+items[j];
            g[i][j].second=2;
        }
    }

    for(int i=1; i<=m; i++){
        cin >> a >> b >> p;
        g[a][b]={p, 2};
        g[b][a]={p, 2};
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(g[i][j].first>(g[i][k].first+g[k][j].first)){
                    g[i][j].first=g[i][k].first+g[k][j].first;
                    g[i][j].second=g[i][k].second+g[k][j].second;
                }
                else if(g[i][j].first==(g[i][k].first+g[k][j].first)){
                    g[i][j].second=max(g[i][j].second, g[i][k].second+g[k][j].second);
                }
            }
        }
    }

    while(q--){
        cin >> a >> b;
        cout << g[a][b].first << " " << g[a][b].second << "\n";
    }

    return 0;
}