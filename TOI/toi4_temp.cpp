#include <bits/stdc++.h>

using namespace std;
int sizee;
int num[21][21], visitt[21][21], g[21][21];
vector<int> ans;

int isValid(int x, int y){
    if(x<1 || y<1 || x>sizee || y>sizee || visitt[x][y] || num[x][y]==100) return 0;
    return 1;
}

int floodfill(int x, int y){
    visitt[x][y]=1;
    int row[] = {0, -1, 1, 0};
    int col[] = {1, 0, 0, -1};
    int counter=0;
    for(int u=0; u<4; u++){
        if(isValid(x+row[u], y+col[u]) && num[x+row[u]][y+col[u]]>num[x][y]) floodfill(x+row[u], y+col[u]);
        else counter++;
    }

    if(counter==4) ans.push_back(num[x][y]);

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> sizee;
    int rows, cols; //row start col start
    cin >> cols >> rows;
    for(int i=1; i<=sizee; i++){
        for(int j=1; j<=sizee; j++){
            cin >> num[i][j];
        }
    }
    floodfill(rows, cols);

    sort(ans.begin(), ans.end());

    //for(auto a:ans) cout << a << " ";
    int s=ans.size();
    cout << ans[s-1];

    return 0;
}