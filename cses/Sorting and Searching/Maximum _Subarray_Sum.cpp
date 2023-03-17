#include <bits/stdc++.h>

using namespace std;
int n, num;
vector<int> vec;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        vec.push_back(num);
    }

    long long sum=0, ans=vec[0];
    for(int i=0; i<n; i++){
        if(sum<0) sum=vec[i];
        else sum+=vec[i];
        ans=max(ans, sum);
    }

    cout << ans;

    return 0;
}