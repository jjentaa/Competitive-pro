#include <bits/stdc++.h>

using namespace std;
const int mxN=5e5;
long long n;
long long minn=LLONG_MAX, qs[mxN+1], sum, ans=LLONG_MAX, hole;
array<long long, 2> arr[mxN];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i][1];
        minn=min(minn, arr[i][1]);
    }

    for(int i=0; i<n; i++) cin >> arr[i][0];
    sort(arr, arr+n);

    for(int i=1; i<=n; i++){
        qs[i]=qs[i-1]+arr[i-1][1];
        sum+=arr[i-1][0];
    }

    for(int i=0; i<n; i++){
        if(arr[i][0]>minn) break;
        if(ans>sum+qs[i]-n*arr[i][0]){
            ans=sum+qs[i]-n*arr[i][0];
            hole=arr[i][0];
        }
    }

    cout << hole << " " << ans;
    
    return 0;
}