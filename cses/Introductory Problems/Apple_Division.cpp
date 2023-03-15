#include <bits/stdc++.h>

using namespace std;
int n, arr[21];
long long dif[21];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    long long mx=0;
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dif[i] += abs(arr[j]-arr[i]);
        }
        if(mx<dif[i]){
            mx=dif[i];
            ans=arr[i];
        }
    }

    cout << ans;

    return 0;
}