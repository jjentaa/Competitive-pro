#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    int counter=1, pivot=vec[0];
    for(int i=1; i<n; i++){
        if(vec[i]!=pivot){
            pivot=vec[i];
            counter++;
        }
    }

    cout << counter;

    return 0;
}