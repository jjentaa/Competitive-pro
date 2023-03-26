#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int sumArr(int f, int s){
    int sum=0;
    for(int j=f; j<=s; j++){
        sum += arr[j];
    }
    return sum;
}

int findAns(int start, int end){
    if(start == end){
        return start+1;
    }
    else{
        if(arr[start] >= arr[end]){
            cout << sumArr(start+1, end) << "\n";
            return findAns(start+1, end);
        }
        else{
            cout << sumArr(start, end-1) << "\n";
            return findAns(start, end-1);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << sumArr(0, n-1) << "\n";
    cout << findAns(0, n-1);

    return 0;
}