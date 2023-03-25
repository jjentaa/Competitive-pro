#include <bits/stdc++.h>

using namespace std;
int m, n, k, l, c, num;
int qs[10000005];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k >> l;

    for(int i=0; i<n; i++){
        cin >> c;
        qs[c]=1;
    }

    for(int i=0; i<=10000002; i++) qs[i]+=qs[i-1];

    for(int i=0; i<k; i++){
        int counter=0, s=0, d=0;
        for(int j=0; j<m; j++){
            cin >> num;
            s=max(d, num-l-1); // if have double line
            d=min(10000000, num+l);
            counter+=(qs[d]-qs[s]);
        }
        cout << counter << "\n";
    }

    return 0;
}