#include <bits/stdc++.h>

using namespace std;
vector<int> attack;
pair<int, int> stat;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n;
    for(int j=0; j<2*n; j++){
        cin >> x;
        attack.push_back(x);
    }
    stat.first = n;
    stat.second = n;

    int i=1, counterE=0, counterO=0;
    if(attack[0]%2){
        counterO++;
        stat.second-=1;
    }
    else{
        counterE++;
        stat.first-=1;
    }
    while((stat.first>0)&&(stat.second>0)){
        //odd
        if(attack[i]%2){
            if(attack[i-1]%2==attack[i]%2){
                counterO++;
            }
            else{
                counterO=0;
            }

            if(counterO>=3){
                stat.second -= 3;
            }
        }
        //even
        else{
            if(attack[i-1]%2==attack[i]%2){
                counterE++;
            }
            else{
                counterE=0;
            }
            if(counterO>=3){
                stat.first -= 3;
            }
        }
        i++;
    }
    if(stat.first>0){
        cout << 1 << "\n" << attack[i];
    }
    else{
        cout << 0 << "\n" << attack[i];
    }

    return 0;
}