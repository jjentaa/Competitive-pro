#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int height[n], poduim[n];

    for(int i=0; i<n; i++){
        cin >> height[i];
    }

    for(int i=0; i<n; i++){
        cin >> poduim[i];
    }
    
    sort(height, height+n);
    sort(poduim , poduim+n , greater<int>());

    int total[n];
    for(int z=0; z<n; z++){
        total[z] = poduim[z]+height[z];
    }

    long long max=LLONG_MIN, min=LLONG_MAX;
    for(int u=0; u<n; u++){
        if(total[u]>max){
            max = total[u];
        }
        if(total[u]<min){
            min = total[u];
        }
    }

    cout << max-min;

    return 0;
}