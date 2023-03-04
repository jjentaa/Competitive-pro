#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            vec.push_back(i);
            if(n/i != i){
                vec.push_back(n/i);
            }
        }
    }

    sort(vec.begin(), vec.end());
    for(auto v: vec){
        cout << v << " ";
    }

    return 0;
}