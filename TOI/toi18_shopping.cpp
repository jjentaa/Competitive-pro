#include <bits/stdc++.h>

using namespace std;
int shop[500001];
int point[500001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x<0){
            shop[i+1] = shop[i]-x;
            point[i+1] = point[i];
        }
        else{
            shop[i+1] = shop[i];
            point[i+1] = point[i]+x;
        }
    }

    int start, money, rhs, lhs, mid;
    for(int j=0; j<q; j++){
        cin >> start >> money;
        lhs = start+1;
        rhs = n;
        if(money > shop[n]){
            cout << point[n]-point[start] <<"\n";
        }
        else{
            while(lhs<rhs){
                mid = (rhs+lhs)/2;
                //cout << lhs << " " << rhs<< "mid=" << mid << " " << shop[mid]-shop[start] << "\n";
                if(shop[mid]-shop[start]<money){
                    lhs = mid+1;
                }
                else{
                    rhs = mid;
                }
            }
            cout << point[rhs]-point[start] << "\n";
        }
    }

    //display shop and point
    // for(int y=0; y<n+1; y++){
    //     cout << shop[y] << " ";
    // }
    // cout << "\n";
    // for(int y=0; y<n+1; y++){
    //     cout << point[y] << " ";
    // }

    return 0;
}