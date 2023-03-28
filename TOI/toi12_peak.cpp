#include <bits/stdc++.h>

using namespace std;
long long arr[5000002];
long long n, k;
vector<long long> ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n; i++) if(arr[i]>arr[i-1] && arr[i] > arr[i+1]) ans.push_back(arr[i]);

    if(ans.empty()){
        cout << -1;
        return 0;
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    if(ans.size()>=k) reverse(ans.begin(), ans.end());
    for(long long i=0; i<min((long long)ans.size(), k); i++) cout << ans[i] << "\n";

    return 0;
}