#include <bits/stdc++.h>

using namespace std;
const int mx=2e5;
long long n, target, counter;
long long arr[mx], qs[mx+1], total;
map<long long, long long> mpp;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> target;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        total+=arr[i];
        if(total==target) counter++;
        if(mpp.count(total-target)) counter+=mpp[total-target];
        mpp[total]++;
    }

    cout << counter;

    return 0;
}