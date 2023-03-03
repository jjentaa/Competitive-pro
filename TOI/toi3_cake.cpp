#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    float a, b, c, d, e;
    float total=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c >> d >> e;
        total+=(a)+(b*3/4)+(c*1/2)+(d*1/4)+(e*1/8);
        //cout << (a)+(b*3/4)+(c*1/2)+(d*1/4)+(e*1/8);
    }

    cout << ceil(total);

    return 0;
}