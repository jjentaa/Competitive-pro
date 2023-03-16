#include <bits/stdc++.h>

using namespace std;
vector<int> vec1, vec2;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, numbefore;
    cin >> n;

    long long total=(n*(n+1))/2;
    if(total%2){
        cout << "NO";
        return 0;
    }

    cout << "YES" << "\n";

    if(n%4==3){
        numbefore=3;
        vec1.push_back(1);
        vec1.push_back(2);
        vec2.push_back(3);
    }
    else{
        numbefore=4;
        vec1.push_back(1);
        vec1.push_back(4);
        vec2.push_back(2);
        vec2.push_back(3);
    }

    for(int i=0; i<(n-1)/4; i++){
        vec1.push_back(4*i+1+numbefore);
        vec1.push_back(4*i+4+numbefore);
        vec2.push_back(4*i+2+numbefore);
        vec2.push_back(4*i+3+numbefore);
    }

    cout << vec1.size() << "\n";
    for(auto k: vec1) cout << k << " ";

    cout << "\n" << vec2.size() << "\n";
    for(auto k: vec2) cout << k << " ";

    return 0;
}