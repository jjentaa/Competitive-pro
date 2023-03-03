#include <bits/stdc++.h>

using namespace std;
vector<int> attack;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n;
    for(int j=0; j<2*n; j++){
        cin >> x;
        attack.push_back(x);
    }
    int hp0=n, hp1=n;

    int counter0=0, counter1=0;
    for(int i=0; i<2*n; i++){
        if(attack[i]%2){
            counter0=0;
            counter1++;
            if(counter1>=3) hp0-=3; 
            else hp0--;
        }
        else{
            counter1=0;
            counter0++;
            if(counter0>=3) hp1-=3; 
            else hp1--;
        }
        if(hp0<=0){
            cout << 1 << "\n" << attack[i];
            break;
        }
        if(hp1<=0){
            cout << 0 << "\n" << attack[i];
            break;
        }
    }


    return 0;
}