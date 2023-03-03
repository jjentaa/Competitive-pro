#include <bits/stdc++.h>

using namespace std;
queue<int> que;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) que.push(i);

    int counter=0;
    while(!que.empty()){
        counter++;
        if(counter%m==0){
            cout << que.front() << " ";
            que.pop();
        }
        else{
            que.push(que.front());
            que.pop();
        }
    }

    return 0;
}