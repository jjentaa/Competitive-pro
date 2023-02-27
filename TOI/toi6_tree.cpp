#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=0; i<5; i++){
        int n;
        cin >> n;
        map<vector<pair<int, int> >, int> ma;
        vector<pair<int, int> > g1, g2;
        for(int j=0; j<n-1; j++){
            int m, n;
            pair<int, int> p;
            cin >> m >> n;
            p.first=m, p.second=n;
            g1.push_back(p);
            p.first=n, p.second=m;
            g1.push_back(p);
        }
        for(int k=0; k<n-1; k++){
            int m, n;
            pair<int, int> p;
            cin >> m >> n;
            p.first=m, p.second=n;
            g2.push_back(p);
            p.first=n, p.second=m;
            g2.push_back(p);
        }
        sort(g1.begin(), g1.end());
        sort(g2.begin(), g2.end());

        ma[g1]=1;

        if(ma[g2]) cout << "Y";
        else cout << "N";

    }

    return 0;
}