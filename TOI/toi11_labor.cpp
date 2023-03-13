#include <bits/stdc++.h>

using namespace std;
long long n, mx=1, m;
vector<long long> vec;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<m; i++){
        long long num;
        cin >> num;
        vec.push_back(num);
        mx=max(mx, num);
    }

    long long l=0, r=mx*n; //max time is the max one do all
    while(l<r){
        long long mid=((l+r)/2);
        long long total=0;
        for(int i=0; i<m; i++){
            total+=mid/vec[i]; // piece of work per worker
            if(total>=n) break;
        }
        if(total<n) l=mid+1;
        else r=mid;
    }

    cout << l;

    return 0;
}