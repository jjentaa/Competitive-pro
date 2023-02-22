#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, row, column, l, max;
    cin >> n;
    bool mat[n][71];
    memset(mat, false, sizeof(mat));

    for(int i=0; i<n; i++){
        cin >> row;
        cin >> column;
        cin >> l;
        if(column+l > 70){
            max=70;
        }
        else{
            max=l+column-1;
        }
        for(int j=column-1; j<max; j++){
            mat[row-1][j] = true;
        }
    }

    // for(int c=0; c<n; c++){
    //     for(int d=0; d<70; d++){
    //         cout << arr[c][d];
    //     }
    //     cout << "\n";
    // }

    //display
    for(int c=0; c<n; c++){
        for(int d=0; d<70; d++){
            if(mat[c][d]){
                cout << "x";
            }
            else{
                cout << "o";
            }
        }
        cout << "\n";
    }

    return 0;
}