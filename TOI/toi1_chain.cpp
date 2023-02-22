#include <bits/stdc++.h>

using namespace std;
string all_word[30001];
int main(){
    int l, n, counter, index=0, ans=0;
    bool find=false;
    cin >> l;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> all_word[i];
    }
    for(int j=0; j<n-1; j++){
        if(!find){
            counter=0;
            for(int k=0; k<l; k++){
                if(all_word[j][k]!=all_word[j+1][k]){
                    counter++;
                }
                if(counter>2){
                    break;
                }
            }
            if(counter>2){
                cout << all_word[j];
                find=true;
                break;
            }
        }
        ans++;
    }
    // if(ans==n-2){
    //     cout << all_word[n-1];
    // }
    if(!find){
        cout << all_word[n-1];
    }

    return 0;
}