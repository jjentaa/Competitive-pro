#include <bits/stdc++.h>

using namespace std;
int n, num;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        auto it=lower_bound(dp.begin(), dp.end(), num);
        if(it==dp.end()) dp.push_back(num);
        else *it=num; // smaller one can potentially make the subsequence longer
    }

    cout << dp.size();

    return 0;
}