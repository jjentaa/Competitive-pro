#include <bits/stdc++.h>

using namespace std;
int window[4001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h, n;
    cin >> w >> h >> n;
    int start, l;
    for(int i=0; i<n; i++){
        cin >> start >> l;
        window[start]++;
        window[start+l]--;
    }

    int pivot=0;
    int c50=0, c100=0;
    for(int j=0; j<w; j++){
        pivot += window[j];
        window[j] = pivot;
        if(pivot==0){
            c100++;
        }
        if(pivot==1){
            c50++;
        }
    }

    cout << c100*h << " " << c50*h;

    // display window
    // for(int i=0; i<w; i++){
    //     cout << window[i] << " ";
    // }

    return 0;
}