#include <bits/stdc++.h>

using namespace std;
int n;
long long q;

long long power10(int target){
    long long res=1;
    for(int i=0; i<target; i++) res*=10;
    return res;
}

int solve(long long sth){
    if(sth<9) return (int) sth+1;

    int digit=1;
    while(9*power10(digit-1)*digit<sth){
        sth-=9*power10(digit-1)*digit;
        digit++;
    }

    string num=to_string(power10(digit-1)+sth/digit);
    //cout << num << " ";
    return (int) (num[sth%digit]-'0');

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> q;
        cout << solve(q-1) << "\n";
    }

    return 0;
}