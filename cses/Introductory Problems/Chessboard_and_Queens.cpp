#include<bits/stdc++.h>

using namespace std;
int a[10][10], c[10];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=1; i<=8; i++){
        string s;
        cin >> s;
        for(int j=0; j<8; j++){
            if(s[j]=='*') a[i][j+1]=1;
        }
    }
    for(int i=1; i<=8; i++) c[i]=i;
    int counter=0;
    do{
        int ch=0;
        for(int i=1; i<=8; i++){
            if(a[i][c[i]]){
                ch=1;
                break;
            }
        }
        for(int i=1; i<=7; i++){
            for(int j=i+1; j<=8; j++){
                if(j-i==abs(c[j]-c[i])){
                    ch=1;
                    break;
                }
            }
            if(ch) break;
        }
        if(!ch) counter++;
    }while(next_permutation(c+1,c+9));
    cout << counter;

    return 0;
}