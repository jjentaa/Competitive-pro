#include <bits/stdc++.h>

using namespace std;
	
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
    queue<char> start, mover;
	int n;
    char num;
	cin >> n;
	for(int i=0; i<n; i++){
        cin >> num;
        start.push(num), mover.push(num);
	}
	
	for(int i=1; i<n; i++){
        mover.push(mover.front());
        mover.pop();
        if(n%i==0 && mover==start){
            cout << i;
            return 0;
        }
	}
	cout << n;
	
	return 0;
}