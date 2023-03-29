#include <bits/stdc++.h>

using namespace std;
int n, counter, inside;
string s;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q=20;
    
    while(q--){
        counter=0, inside=0;
        cin >> n >> s;
        if(s=="02" || (s[0]=='0' && s[1]=='2')){
            cout << "yes\n";
            continue;
        }
        if(s[0]!='0'){
            cout << "no\n";
            continue;
        }
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                counter++;
                if(i>1) inside++;
            }
        }
        if(counter==0 || (counter==n && counter%2==0) || (s[0]=='0' && s[1]!='2' && inside==0)){
            cout << "no\n";
            continue;
        }
        cout << "yes\n";
    }

    return 0;
}