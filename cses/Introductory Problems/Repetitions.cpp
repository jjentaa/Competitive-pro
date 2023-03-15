#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string target;
    cin >> target;

    int counter=1, ans=1;
    char pivot = target[0];
    for(int i=1; i<target.size(); i++){
        if(target[i]==pivot){
            counter++;
        }
        else{
            counter=1;
            pivot=target[i];
        }
        ans=max(counter, ans);
    }

    cout << ans;

    return 0;
}