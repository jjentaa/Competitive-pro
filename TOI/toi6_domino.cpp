#include <bits/stdc++.h>

using namespace std;
int num;
void solve(int row, string ans){
    if(row>num) return ;
    if(row==num){
        for(int i=0; i<ans.size(); i+=2){
            cout << ans[i] << ans[i+1] << "\n";
        }
        cout << "E" << "\n";
    }
    else{
        solve(row+1, ans+"--");
        solve(row+2, ans+"||");
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> num;
    solve(0, "");

    return 0;
}