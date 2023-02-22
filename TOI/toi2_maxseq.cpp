#include <bits/stdc++.h>

using namespace std;
int arr[2500], qs[2501];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        qs[i+1]=qs[i]+arr[i];
    }
    int sum = INT_MIN, start, end;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(qs[j]-qs[i-1]>sum && qs[j]-qs[i-1]>0){
                sum=qs[j]-qs[i-1];
                start=i-1;
                end=j;
            }
        }
    }

    if(sum==INT_MIN) cout << "Empty sequence";
    else{
        for(int m=start; m<end; m++) cout << arr[m] << " ";
        cout << "\n" << sum;
    }

    return 0;
}