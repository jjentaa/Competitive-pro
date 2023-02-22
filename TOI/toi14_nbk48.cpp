#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, q, x, money;
    cin >> n >> q;
    int qs[n+1];
    qs[0] = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        qs[i+1] = qs[i]+x;
    }
    //display qs
    // for(int y=0; y<n+1; y++){
    //     cout << qs[y] << " ";
    // }
    //cout << "\n";

    for(int i=n-1;i>0;i--){
        qs[i] = min(qs[i],qs[i+1]);
    }

    //display qs
    // for(int y=0; y<n+1; y++){
    //     cout << qs[y] << " ";
    // }

    int mid, lhs, rhs;
    while(q>0){
        cin >> money;
        lhs = 0;
        rhs = n;
        while(lhs<rhs){
            mid = (lhs+rhs+1)/2;
            if(money<qs[mid]){
                rhs = mid-1;
            }
            else{
                lhs = mid;
            }
        }
        cout << lhs << "\n";
        // if(lhs > 0){
        //     cout << lhs << "\n";
        // }
        // else{
        //     cout << "0" << "\n";
        // }
        q--;
    }

    return 0;
}