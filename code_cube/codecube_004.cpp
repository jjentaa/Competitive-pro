#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b) {
    int temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long long arr[n+1];
    long long GCD, x;
    cin >> arr[0];
    GCD = arr[0];
    for(int i=1; i<n; i++){
        cin >> arr[i];
        GCD = gcd(GCD, arr[i]);
    }
    long long result=0;
    for(int j=0; j<n; j++){
        result += arr[j]/GCD;
    }
    cout << result;

    return 0;
}