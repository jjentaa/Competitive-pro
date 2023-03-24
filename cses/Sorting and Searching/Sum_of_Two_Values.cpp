#include <bits/stdc++.h>

using namespace std;
const int mxN=2e+5;
int n, i;
long long x, num;
pair<long long, int> pr[mxN+2];

int finder(long long target, int l){
    int r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(pr[mid].first==target) return pr[mid].second;
        if(pr[mid].first>target) r=mid-1;
        else l=mid;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x;
    for(int j=1; j<=n; j++){
        cin >> num;
        pr[j]={num, j};
    }

    sort(pr+1, pr+n+1);
    //reverse(pr+1, pr+n+1);
    for(i=1; i<=n; i++){
        int result=finder(x-pr[i].first, i);
        if(result==0) continue;
        else{
            cout << result << " " << pr[i].second;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}