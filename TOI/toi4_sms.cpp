#include <bits/stdc++.h>

using namespace std;
string ans;
string number[9]={"DEL", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
int idx;
int press(int pos, int npress){
    if(pos==0){
        for(int i=0; i<npress; i++){
            if(ans.size()!=0) ans.pop_back();
        }
    }
    else{
        if(pos==6 || pos==8) ans+=number[pos][(npress-1)%4];
        else ans+=number[pos][(npress-1)%3];
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, start, npress, pos=0;
    cin >> n;
    cin >> pos >> npress;
    pos--;
    press(pos, npress);

    for(int i=0; i<n-1; i++){
        //cout << pos << "\n";
        int h, v;
        cin >> h >> v >> npress;
        pos += (v*3)+h;
        press(pos, npress);
    }
    if(ans.empty()) cout << "null";
    else cout << ans;
    
    return 0;
}