#include <bits/stdc++.h>

using namespace std;
int main(){
    vector<int> vec[25];
    string chain;
    vec[0].push_back(1);
    vec[0].push_back(1);
    vec[0].push_back(0);
    for(int i=1; i<25; i++){
        vec[i].push_back(1);
        vec[i].push_back(1+vec[i-1][1]+vec[i-1][2]);
        vec[i].push_back(vec[i-1][1]);
    }
    int c;
    cin >> c;
    while(c != -1){
        cout << vec[c][1] << " " << vec[c][0]+vec[c][1]+vec[c][2] << "\n";
        cin >> c;
    }

    return 0;
}