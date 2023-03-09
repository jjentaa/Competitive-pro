#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string num;
        cin >> num;
        int y=num.size()-1;
        if(num[y]=='1' || num[y]=='3' || num[y]=='5' || num[y]=='7' || num[y]=='9') cout << "T" << "\n";
        else if(num.size()==1 && num[y]=='2') cout << "T" << "\n";
        else cout << "F" << "\n";
    }

    return 0;
}