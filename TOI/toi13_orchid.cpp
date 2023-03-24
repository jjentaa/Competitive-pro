#include <bits/stdc++.h>

using namespace std;
int n, counter=1, num;
vector<int> sorted;
int vec[1000001];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> vec[i];
    }
    for(int i=1; i<=n; i++){
        auto it=upper_bound(sorted.begin(), sorted.end(), vec[i]);
        if(it == sorted.end()) sorted.push_back(vec[i]);
        else *it=vec[i];
    }

    cout <<n-sorted.size();

    return 0;
}