#include <bits/stdc++.h>

using namespace std;
const int mxN=1e5;
int arr[mxN+1];
int n, m, k;

bool isValid(long long mid){
    int counter=0, g=0;
    long long total=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        if(g==m) break;
        total+=arr[i];
        pq.push(arr[i]);
        counter++;

        if(counter>k){
            counter--;
            total-=pq.top();
            pq.pop();
        }

        if(counter==k && total>=mid){
            g++;
            counter=0;
            total=0;
            while(!pq.empty()) pq.pop();
        }
    }
    return g==m;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    long long l=0, r=1e12;
    while(l<=r){
        long long mid=(l+r+1)/2;
        if(!isValid(mid)) r=mid-1;
        else l=mid+1;
    }

    cout << l-1;

    return 0;
}