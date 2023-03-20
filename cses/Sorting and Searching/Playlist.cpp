#include <bits/stdc++.h>

using namespace std;
const int Mx=2e5;
int n;
int arr[Mx];
string text;
int solve(int arr[]){
    map<int, int> umpp;
    int ans=0;
    int j=0;
    for(int i=0; i<n; i++){
        j=max(umpp[arr[i]], j);
        ans=max(ans, i-j+1);
        umpp[arr[i]]=i+1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << solve(arr);

    return 0;
}