#include <bits/stdc++.h>

using namespace std;
int g[18][18];
int visitt[18][18];
int row[]={1, -1, 0, 0};
int col[]={0, 0, 1, -1};
int result;
queue<pair<int, int> > q;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> g[i][j];
        }
    }

    //flood fill
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(g[i][j]!=0 || visitt[i][j]==1){
                int counter=1;
                int upperRow=i, lowerRow=i, upperCol=j, lowerCol=j;
                q.push({i, j});
                int num = g[i][j];
                visitt[i][j]=1;

                while(!q.empty()){
                    int x=q.front().first, y=q.front().second;
                    q.pop();

                    for(int m=0; m<4; m++){
                        int newx=x+row[m], newy=y+col[m];
                        if(g[newx][newy]==num && visitt[newx][newy]==0){
                            counter++;
                            visitt[newx][newy]=1;
                            q.push({newx, newy});
                            // if it fit the pattern it contain 2 row, 2 col so the dis of max row or col and min row or col will be 1
                            upperRow=min(upperRow, newx);
                            upperCol=min(upperCol, newy);
                            lowerRow=max(lowerRow, newx);
                            lowerCol=max(lowerCol, newy);
                        }
                    }
                }
                if(counter==3 && lowerCol-upperCol==1 && lowerRow-upperRow==1){
                    result++;
                }
            }
        }
    }

    cout << result;

    return 0;
}