#include <bits/stdc++.h>

using namespace std;
void solve(int pivot, int startt, int endd, int waitt){
    if(pivot==1){
        cout << startt << " " << endd << "\n";
        return ;
    }
    solve(pivot-1, startt, waitt, endd);
    cout << startt << " " << endd << "\n";
    solve(pivot-1, waitt, endd, startt);
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    cout << pow(2, n)-1 << "\n";
    solve(n, 1, 3, 2);
    return 0;
}