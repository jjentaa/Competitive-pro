#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int main() {
    int row, column, size, max, total;
    cin >> row >> column;
    cin >> size;

    int mat[row][column];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            cin >> mat[i][j];
        }
    }

    for(int a=0; a<row; a++){
        for(int b=0; b<column; b++){
            arr[a+1][b+1] = arr[a][b+1] + arr[a+1][b] + mat[a][b] - arr[a][b];
        }
    }

    max = arr[0][0];
    for(int k=1; k<=row-size+1; k++){
        for(int l=1; l<=column-size+1; l++){
            total = arr[k+size-1][l+size-1]-arr[k-1][l+size-1]-arr[k+size-1][l-1]+arr[k-1][l-1];
            if(total > max){
                max=total;
            }
        }
    }

    cout << max;
    
    return 0;
}