#include <bits/stdc++.h>

using namespace std;
int dice[6];
int spin(char typey){
    if(typey=='F'){
        swap(dice[1], dice[5]);
        swap(dice[0], dice[3]);
        swap(dice[1], dice[3]);
    }
    if(typey=='B'){
        swap(dice[0], dice[1]);
        swap(dice[3], dice[5]);
        swap(dice[1], dice[3]);
    }
    if(typey=='L'){
        swap(dice[0], dice[4]);
        swap(dice[2], dice[5]);
        swap(dice[2], dice[4]);
    }
    if(typey=='R'){
        swap(dice[4], dice[5]);
        swap(dice[0], dice[2]);
        swap(dice[2], dice[4]);
    }
    if(typey=='C'){
        swap(dice[1], dice[4]);
        swap(dice[3], dice[4]);
        swap(dice[2], dice[3]);
    }
    if(typey=='D'){
        swap(dice[1], dice[4]);
        swap(dice[1], dice[2]);
        swap(dice[2], dice[3]);
    }
    return 0;

}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int start=2, dis=0;
        string seq;
        cin >> seq;
        dice[0]=1, dice[1]=2, dice[2]=3, dice[3]=5, dice[4]=4, dice[5]=6;
        for(int j=0; j<seq.size(); j++) spin(seq[j]);
        cout << dice[1] << " ";
    }

    return 0;
}