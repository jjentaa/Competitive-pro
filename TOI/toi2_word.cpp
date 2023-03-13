#include <bits/stdc++.h>

using namespace std;
char arr[30][30];
int m, n;
int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int isValid(int x, int y){
    if(x<1 || y<1 || x>m || y>n) return 0;
    return 1;
}

int searchPat(string target){
    int len=target.size();

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            //if(arr[i][j]!=target[0]) break;
            for(int k=0; k<8; k++){
                int l;
                for(l=0; l<len; l++){
                    if(arr[i+(l*row[k])][j+(l*col[k])]==target[l] && isValid(i+(l*row[k]), j+(l*col[k])))continue;
                    else break;
                }
                if(l==len){
                    cout << i-1 << " " << j-1 << "\n";
                    return 0;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string sth;
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        cin >> sth;
        for(int j=0; j<sth.size(); j++){
            char idk=tolower(sth[j]);
            arr[i][j+1]=idk;
        }
    }

    int q;
    string target;
    cin >> q;
    while(q--){
        cin >> target;
        for(int u=0; u<target.size(); u++){
            target[u]=tolower(target[u]);
        }
        searchPat(target);
    }

    return 0;
}