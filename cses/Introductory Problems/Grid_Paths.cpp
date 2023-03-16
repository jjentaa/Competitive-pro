#include <bits/stdc++.h>

using namespace std;
string path;
int counter, visitt[8][8];
int isValid(int x, int y){
    if(1>x || 1>y || x>7 || y>7 || visitt[x][y]) return 0;
    return 1;
}

void dfs(int x, int y, int step){
    if((!isValid(x+1, y)) && (!isValid(x-1, y) ))
        if(isValid(x, y-1) && isValid(x, y+1))
            return;
    if((!isValid(x, y+1)) && (!isValid(x, y-1) ))
        if(isValid(x+1, y) && isValid(x-1, y))
            return;
    if(x==7 && y==1){
        if(step==48) counter++;
        return ;
    }
    visitt[x][y]=1;
    if(path[step]=='?' || path[step]=='L'){
        if(isValid(x, y-1)) dfs(x, y-1, step+1);
    }
    if(path[step]=='?' || path[step]=='R'){
        if(isValid(x, y+1)) dfs(x, y+1, step+1);
    }
    if(path[step]=='?' || path[step]=='U'){
        if(isValid(x-1, y)) dfs(x-1, y, step+1);
    }
    if(path[step]=='?' || path[step]=='D'){
        if(isValid(x+1, y)) dfs(x+1, y, step+1);
    }
    visitt[x][y]=0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> path;
    dfs(1, 1, 0);

    cout << counter;

    return 0;
}