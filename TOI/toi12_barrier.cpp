#include <bits/stdc++.h>

using namespace std;
int n, w, range;
long long num, keeper, maxx;
deque<pair<int, long long>> dq;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> w;

    for(int i=1; i<=n; i++){
        cin >> num;
        keeper+=num;
        //more range than given
        while(!dq.empty() && i-dq.front().first>w) dq.pop_front();
        //negative num คร่อม
        while(!dq.empty() && dq.back().second>keeper) dq.pop_back();
        dq.push_back({i, keeper});
        //qs
        long long summ=keeper-dq.front().second;
        int r=i-dq.front().first;
        if(summ>=maxx){
            maxx=summ;
            range=r;
        }
    }

    cout << maxx << "\n" << range;

    return 0;
}