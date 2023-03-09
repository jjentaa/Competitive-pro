#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > ans, coor; 
int compare(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first != b.first) return a.first>b.first;
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    pair<int, int> cor;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cor.first >> cor.second;
        coor.emplace_back(cor);
    }
    sort(coor.begin(), coor.end(), compare);
    // for(int i=0; i<n; i++){
    //     cout << coor[i].first << " " << coor[i].second << "\n";
    // }
    int max=0;
    for(int i=0; i<n; i++){
        if(coor[i].second>=max){
            ans.emplace_back(coor[i]);
            max = coor[i].second;
        }
    }
    sort(ans.begin(), ans.end(), compare);
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x.first << " " << x.second << '\n';
    return 0;
}