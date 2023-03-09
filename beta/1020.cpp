#include <bits/stdc++.h>

using namespace std;
int arr[201], n;
string s;
int isPa(int start, int end, int a){
    int counter=0;
    for(int i=0; i<(end-start)/2; i++){
        //cout << i+start << " " << end-i-start+a << "\n";
        //cout << arr[i+start] << " " << arr[end+i-start-a] << "\n";
        if(arr[i]==arr[end-i-1]){
            counter++;
        }
        else{
            break;
        }
    }
    if(counter==(end-start)/2){
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = s.size();

    for(int i=0; i<n; i++){
        if(s[i]>=97 && s[i]<=122){
            arr[i]=s[i]-32;
        }
        else{
            arr[i]=s[i];
        }
        //cout << arr[i] << " ";
    }
    // cout << isPa(0, n, -1);
    // cout << "\n";
    // cout << isPa(0, n/2, 0);
    // cout << "\n";
    // cout << isPa(n/2, n, n/2-1);
    if(isPa(0, n/2, 0) && isPa(n/2, n, n/2-1) && isPa(0, n, -1)){
        cout << "Double Palindrome";
    }
    else if(isPa(0, n, -1)){
        cout << "Palindrome";
    }
    else{
        cout << "No";
    }

    return 0;
}