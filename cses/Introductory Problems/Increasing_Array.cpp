#include <bits/stdc++.h>

using namespace std;
long long ans=0;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, pivot, num;
    cin >> n;
    cin >> pivot;
    for(int i=1; i<n; i++){
        cin >> num;
        if(num<pivot){
            ans+=pivot-num;
        }
        else pivot=num;
    }

    cout << ans;

    return 0;
}