#include <bits/stdc++.h>

using namespace std;
int main(){
    bool num[8000000];
    int n, counter = 0, target=0;
    cin >> n;
    memset(num, true, sizeof(num));
    num[0] = false;
    num[1] = false;
    // for(int i=0; i<10; i++){
    //     cout << num[i] << " ";
    // }
    for (long long i = 2; i < 8000000; i++) {
        if (num[i]) {
            for (long long j = i * i; j < 8000000; j += i){
                num[j] = false;
            }
        }
    }
    while(counter<n){
        if(num[target]){
            counter++;
        }
        target++;
    }
    cout << target-1;

    return 0;
}