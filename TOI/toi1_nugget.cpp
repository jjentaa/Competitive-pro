#include <bits/stdc++.h>

using namespace std;
int isNugget(int num){
    if(num==0 || num==6 || num==9 || num==20){
        return 1;
    }
    if(num<6){
        return 0;
    }
    int a=num-6, b=num-9, c=num-20;
    if((isNugget(a)==1 && a>=0) || (isNugget(b)==1 && b>=0) || (isNugget(c)==1 && c>=0)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    if(n>=6){
        for(int i=6; i<=n; i++){
            if(isNugget(i)){
                cout << i << "\n";
            }
        }
    }
    else{
        cout << "no";
    }

    return 0;
}