#include <bits/stdc++.h>

/* using upper bound -1 in normal case cannot delete upper_bound-1 so use invert way*/
using namespace std;
int n, m;
int num;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    multiset<int> prices;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> num;
        prices.insert(-num);
    }


    while(m--){
        cin >> num;
        auto it = prices.lower_bound(-num);
        if(it == prices.end())
            cout << -1 << '\n';
        else {
            cout << -*it << '\n';
            prices.erase(it);
        }
    }

    return 0;
}