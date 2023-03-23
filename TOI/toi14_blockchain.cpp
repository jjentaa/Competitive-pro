#include <bits/stdc++.h>

using namespace std;
int t, q, n, u, v;
map<vector<pair<int, int>>, int> mpp;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t >> q;
    
    for(int i=0; i<t; i++){
        cin >> n;
        vector<pair<int, int>> vec;
        for(int j=0; j<n-1; j++){
            cin >> u >> v;
            vec.push_back({u, v});
            vec.push_back({v, u});
        }
        sort(vec.begin(), vec.end());
        mpp[vec]++;
    }

    for(int i=0; i<q; i++){
        cin >> n;
        vector<pair<int, int>> vec;
        for(int j=0; j<n-1; j++){
            cin >> u >> v;
            vec.push_back({u, v});
            vec.push_back({v, u});
        }
        sort(vec.begin(), vec.end());
        cout << mpp[vec] << "\n";
    }

    return 0;
}