#include <bits/stdc++.h>

using namespace std;
int n;
long long sth;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        sth = 1LL+((i-1)*(i-2)/2);
        sth *= (i-1)*(i+4);
        cout << sth << "\n";
    }

    return 0;
}