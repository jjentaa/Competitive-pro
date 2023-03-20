#include <bits/stdc++.h>

using namespace std;
char g[101][101];
int row[]={1, -1, 0, 0};
int col[]={0, 0, 1, -1};
// D U R L
int visitt[101][101];
int a, b;

struct Data{
    int x, y, t;
    int preX, preY;
};

int isValid(int x, int y){
    if(x<1 || y<1 || x>a || y>b) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            cin >> g[i][j];
        }
    }

    queue<Data> q;
    q.push({1, 1, 1, 0, 0}); //start point time=1
    while(!q.empty()){
        int x=q.front().x, y=q.front().y, t=q.front().t, px=q.front().preX, py=q.front().preY;
        q.pop();
        if(visitt[x][y]){
            cout << t << "\n" << x << " " << y;
            return 0;
        }
        
        visitt[x][y]=1;
        if((g[x][y]=='B' || g[x][y]=='D') && isValid(x+1, y) && px!=x+1){
            q.push({x+1, y, t+1, x, y});
        }
        if((g[x][y]=='B' || g[x][y]=='R') && isValid(x, y+1) && py!=y+1){
            q.push({x, y+1, t+1, x, y});
        }
        if((g[x-1][y]=='B' || g[x-1][y]=='D') && isValid(x-1, y) && px!=x-1){
            q.push({x-1, y, t+1, x, y});
        }
        if((g[x][y-1]=='B' || g[x][y-1]=='R') && isValid(x, y-1) && py!=y-1){
            q.push({x, y-1, t+1, x, y});
        }
    }

    return 0;
}