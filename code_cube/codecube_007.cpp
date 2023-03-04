#include <bits/stdc++.h>

using namespace std;
char S[1000001], M[1000001];
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> S;
    cin >> M;
    bool checker=true;
    if(strlen(S)!=strlen(M)){
        cout << "R.I.P.";
        return 0;
    }

    int size=strlen(M);
    int dis;
    char s, m;
    vector<int> ans;
    for(int j=0; j<size; j++){
        s = toupper(S[j]);
        m = toupper(M[j]);
        dis = (s-m+26)%26;
        if(dis>9){
            cout << "R.I.P.";
            return 0;
        }
        ans.push_back(dis);
    }

    for(auto k:ans){
        cout << k;
    }
    
    //cout << ans;

    return 0;
}