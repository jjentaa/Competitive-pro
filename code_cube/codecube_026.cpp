#include <bits/stdc++.h>

using namespace std;
int line[1000010];
int main(){
    int n, start, end;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> start >> end;
        line[start]++;
        line[end]--;
    }
    int total=line[0], max=0;
    for(int j=1; j<=1000010;j++){
        total+=line[j];
        line[j]=total;
        if(line[j]>max){
            max=line[j];
        }
    }
    cout << max;

    return 0;
}