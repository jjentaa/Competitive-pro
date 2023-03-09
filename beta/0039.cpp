#include <bits/stdc++.h>

using namespace std;
vector<int> warn;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, nwarn, x;
    int arr[10];
    cin >> n;
    cin >> nwarn;
    for(int i=0; i<n; i++){
        arr[i]=i+1;
    }
    for(int i=0; i<nwarn; i++){
        cin >> x;
        warn.push_back(x);
    }
    do{
        if(find(warn.begin(), warn.end(), arr[0])!= warn.end()){
            continue;
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    while(next_permutation(arr, arr+n));


    return 0;
}