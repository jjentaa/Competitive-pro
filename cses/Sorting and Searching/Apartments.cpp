#include <bits/stdc++.h>

using namespace std;
int n, m;
long long k, num;
vector<long long> q;
vector<long long> s;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> num;
        q.push_back(num);
    }

    for(int i=0; i<m; i++){
        cin >> num;
        s.push_back(num);
    }

    sort(q.begin(), q.end());
    sort(s.begin(), s.end());

    int counter=0, j=0;
    for(int i=0; i<n; i++){
        while(j<m && s[j]+k<q[i]) j++;
        if(j<m && s[j]-k<=q[i]){ //minimum case
            counter++;
            j++;
        }
    }

    cout << counter;

    return 0;
}