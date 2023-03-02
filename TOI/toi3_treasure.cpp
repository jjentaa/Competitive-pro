#include <bits/stdc++.h>

using namespace std;
double x, y;
string s;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);

    while(1){
        cin >> s;
        if(s[0]=='*') break;
        double n=0;
        string d;
        for(int j=0; j<s.size(); j++){
            if(s[j]>='0' && s[j]<='9'){
                n*=10;
                n+=s[j]-'0';
            }
            else d+=s[j];
        }

        if(d.size()==2) n/=sqrt(2);
        for(int t=0; t<d.size(); t++){
            if(d[t]=='N') y+=n;
            if(d[t]=='S') y-=n;
            if(d[t]=='E') x+=n;
            if(d[t]=='W') x-=n;
        }

    }

    cout << setprecision(3) << fixed << x << " " << y << "\n";
    cout << setprecision(3) << sqrt(x*x+y*y);

    return 0;
}