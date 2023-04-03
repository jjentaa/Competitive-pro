#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll m, n;
ll g[201][201];
ll movee[6][2]={{0, -1}, {0, 1}, {-1, 0}, {-1, 1}, {1, 0}, {1, 1}};
bool visitt[201][201][402];
queue<pair<pair<ll, ll>, ll>> q;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
        }
    }
    //start [m-1/2][-1] end [m-1/2  ][n-1]
    ll st=(m-1)/2;
    q.push({{st-1, 0}, 1});
    q.push({{st, 0}, 1});
    q.push({{st+1, 0}, 1});

    while(!q.empty()){
        ll x=q.front().first.first, y=q.front().first.second, counter=q.front().second;
        q.pop();
        if(visitt[x][y][counter] || !g[x][y] || x<0 || y<0 || x>m-1 || y>n-1 || counter%g[x][y]!=0) continue;
        visitt[x][y][counter]=true;
        if(x==st && y==n-1){
            cout << counter;
            return 0;
        }
        for(int d=0; d<6; d++){
            ll newX=x+movee[d][0], newY=y+movee[d][1];
            if(movee[d][0]!=0 && x%2==1) newY--;
            if(g[newX][newY]==0) continue;
            if(newX<0 || newY<0 || newX>m-1 || newY>n-1) continue;
            if(((counter+1)%g[newX][newY])!=0) continue;
            q.push({{newX, newY}, counter+1});
        }
    }

    return 0;
}