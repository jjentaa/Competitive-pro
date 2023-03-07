#include <bits/stdc++.h>

using namespace std;
int n;
int solve(int i, string checker){
    if(i==n){
        for(int j=i-1; j>=0; j--){
            string t=checker;
            if(checker[j]=='0'){
                t[j]='1';
                cout << checker << " " << t << "\n";
            }
        }
        return 0;
    }
    solve(i+1, checker+"0");
    solve(i+1, checker+"1");
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    solve(0, "");

    return 0;
}