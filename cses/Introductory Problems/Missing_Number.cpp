#include <bits/stdc++.h>

using namespace std;
int n, num;
vector<int> vec;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    for(int i=0; i<n-1; i++){
        if(vec[i]!=i+1){
            cout << i+1;
            return 0;
        }
    }
    cout << n;
    return 0;
}