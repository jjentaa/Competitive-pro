#include <bits/stdc++.h>

using namespace std;
int allH[256];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, final=INT_MIN, start=INT_MAX;
    cin >> n;
    for(int i=0; i<n; i++){
        int l, h, r;
        cin >> l >> h >> r;
        final=max(final, r);
        start=min(start, l);
        for(int j=l; j<r; j++){
            allH[j]=max(allH[j], h);
        }
    }

    int pivot=-100;
    for(int i=start; i<=final; i++){
        //cout << i << " " << allH[i] <<;
        if(allH[i]!=pivot){
            cout << i << " " << allH[i] << " ";
            pivot = allH[i];
        }
    }
    
    return 0;
}