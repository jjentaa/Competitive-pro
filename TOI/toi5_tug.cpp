#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    long long dis=0;
    cin >> n;
    vector<int> com, dara;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            int num;
            cin >> num;
            if(i==0) com.push_back(num);
            else dara.push_back(num);
        }
    }
    sort(com.begin(), com.end());
    sort(dara.begin(), dara.end());
    for(int i=0; i<n; i++){
        dis += abs(com[i]-dara[i]);
    }
    cout << dis;

    return 0;
}