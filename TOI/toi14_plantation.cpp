#include <bits/stdc++.h>

using namespace std;
vector<pair<long long, long long> > coor;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int w;
    cin >> w;

    while(w--){
        long long n, r, d;
        cin >> n >> r >> d;
        coor.clear();
        for(int i=0; i<n; i++){
            long long x, y;
            cin >> x >> y;
            pair<long long, long long> p;
            p.first=x, p.second=y;
            coor.push_back(p);
        }

        sort(coor.begin(), coor.end());

        long long stand=d+(2*r), checker=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long dx=coor[j].first-coor[i].first;
                long long dy=coor[j].second-coor[i].second;
                if(dx>stand || dy>stand) break;
                if((dx*dx)+(dy*dy)<(stand*stand)){
                    checker=1;
                    break;
                }
            }
            if(checker) break;
        }
        if(checker) cout << "N" << "\n";
        else cout << "Y" << "\n";
    }

    return 0;
}