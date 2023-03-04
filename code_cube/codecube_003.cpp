#include <bits/stdc++.h>

using namespace std;
int findGCD(int x, int y){
    if(y==0){
        return x;
    }
    return findGCD(y, x%y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a;
    cin >> b;
    if(a>b){
        cout << a*b/findGCD(a, b);
    }
    else{
        cout << a*b/findGCD(b, a);
    }

    return 0;
}