#include <bits/stdc++.h>

using namespace std;
int n, num, target;
vector<int> vec;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> target;
    for(int i=0; i<n; i++){
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    int counter=0, idx=0;
    for(int i=n-1; i>=idx; i--){
        if(vec[i]+vec[idx]<=target) idx++;
        counter++;
    }
    cout << counter;

    return 0;
}