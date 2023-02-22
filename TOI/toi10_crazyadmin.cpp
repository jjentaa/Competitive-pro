#include <bits/stdc++.h>

using namespace std;
vector<int> num;
int check(int contain){
    int t=0, box=0;
    for(auto i: num){
        if(box+i > contain){
            t++;
            box = i;
        }
        else{
            box += i;
        }
    }
    if(box!=0){
        t++;
    }
    return t;
}
int main(){
    int o, n, p, lhs=INT_MIN;
    cin >> n >> o;
    for(int i=0; i<o; i++){
        cin >> p;
        num.push_back(p);
        if(p > lhs){
            lhs = p;
        }
    }
    int mid;
    int rhs = 150000;
    while(lhs<rhs){
        mid=(lhs+rhs)/2;
        if(check(mid)>n){
            lhs = mid+1;
        }
        else{
            rhs = mid;
        }
    }
    cout << lhs;

    return 0;
}