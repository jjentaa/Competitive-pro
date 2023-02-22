#include <bits/stdc++.h>

using namespace std;
bool sortFirst(vector<int>& v1, vector<int>& v2)
{
    if(v1[0]!=v2[0]){
        return v1[0] < v2[0];
    }
    else{
        return v1[1] < v2[1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    vector<int> vec[n];
    for(int i=0; i<n; i++){
        cin >> x >> y;
        vec[i].push_back(x);
        vec[i].push_back(y);
    }

    sort(vec, vec+n, sortFirst);

    //display arr
    // for(int j=0; j<n; j++){
    //     cout << vec[j][0] << " " << vec[j][1] << "\n";
    // }

    // cout << "--------------------------------" << "\n";

    for(int y=0; y<n-1; y++){
        if(vec[y][1] > vec[y+1][1]){
            cout << vec[y][0] << " " << vec[y][1] << "\n";
        }
    }
    if(vec[n-1][1]<vec[n-2][1]){
        cout << vec[n-1][0] << " " << vec[n-1][1];
    }

    return 0;
}