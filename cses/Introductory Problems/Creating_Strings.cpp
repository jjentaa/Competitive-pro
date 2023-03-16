#include <bits/stdc++.h>

using namespace std;
int gen[9];
string ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string sth;
    cin >> sth;
    int n=sth.size();
    for(int i=0; i<n; i++){
        gen[i]=sth[i]-97;
    }
    sort(gen, gen+n);

    int counter=0;
    do{
        for(int j=0; j<n; j++){
            ans+=gen[j]+97;
        }
        ans+="\n";
        counter++;
    }
    while(next_permutation(gen, gen+n));
    cout << counter << "\n" << ans;

    return 0;
}