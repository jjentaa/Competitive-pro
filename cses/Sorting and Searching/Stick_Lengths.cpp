#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long sum=0;
    int mid=v[n/2];
    for(auto i: v){
        sum += abs(i-mid);
    }
    cout << sum;
    
    // else{
    //     int mid1=v[n/2], mid2=v[(n/2)-1], sum1=0, sum2=0;
    //     for(auto i: v){
    //         sum1 += abs(i-mid1);
    //         sum2 += abs(i-mid2);
    //     }
    //     if(sum1>sum2) cout << sum2;
    //     else cout << sum1;
    // }

    return 0;
}