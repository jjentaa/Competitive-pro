#include <bits/stdc++.h>

using namespace std;
// int checker(int num){
//     if(num==0){
//         return 0;
//     }
//     if(num>=15){
//         return 3000+checker(num-15);
//     }
//     else if(num>=5){
//         return 1500+checker(num-5);
//     }
//     else if(num>=2){
//         return 800+checker(num-2);
//     }
//     else if(num==1){
//         return 500;
//     }
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, money=0;
    cin >> n;
    while(n>7){
        if(n>=15){
            n -= 15;
        }
        else{
            n = 0;
        }
        money += 3000;
    }
    while(n>3){
        if(n>=5){
            n -= 5;
        }
        else{
            n = 0;
        }
        money += 1500;
    }
    while(n>1){
        if(n>=2){
            n -= 2;
        }
        else{
            n = 0;
        }
        money += 800;
    }
    if(n==1){
        money += 500;
    }

    cout << money;

    return 0;
}