#include <bits/stdc++.h>

using namespace std;
int n, target, counter, num, mover;
vector<int> vec;
long long total;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> target;
    for(int i=0; i<n; i++){
        cin >> num;
        vec.push_back(num);
        total+=num;
        while(total>target){
            total-=vec[mover];
            mover++;
        }
        if(total==target) counter++;
    }

    cout << counter;

    return 0;
}