#include <bits/stdc++.h>

using namespace std;
void solve(int k, int a, int b, string ans){
    if(k==a || k==b){
        cout << ans << "\n";
        return ;
    }
    solve(k, a+1, b, ans+"W ");
    solve(k, a, b+1, ans+"L ");
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int k, a, b;
    cin >> k >> a >> b;
    solve(k, a+1, b, "W ");
    solve(k, a, b+1, "L ");

    return 0;
}