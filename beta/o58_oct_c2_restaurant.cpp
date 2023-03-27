#include <bits/stdc++.h>

using namespace std;
int g[301][301];
bool nAdj[301][301];
int n, t;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> t;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> g[i][j];
        }
    }

    //floyd warshel
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(i==k) continue;
            for(int j=1; j<=n; j++){
                if(i==j || k==j) continue;
                if(g[i][j]==g[i][k]+g[k][j]) nAdj[i][j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++){
        int counter=0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(!nAdj[i][j]) counter++; //count neighbor
        }
        if(counter>=3){
            cout << i;
            if(t==2) cout << "\n" << counter;
            return 0;
        }
    }

    return 0;
}