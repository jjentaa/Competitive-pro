#include <bits/stdc++.h>

using namespace std;
vector<int> id;
long long p1[10], p2[10], p3[10], p21[100], p22[100], p23[100], p33[1000];
long long counter;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        id.push_back(x);
        int a = x/100;
        x%=100;
        int b = x/10;
        x%=10;
        int c = x;
        counter+=p1[a]+p2[b]+p3[c]-p21[(10*a)+b]-p22[(10*b)+c]-p23[(10*a)+c]+p33[(100*a)+(10*b)+c];
        p1[a]++, p2[b]++, p3[c]++;
        p21[(10*a)+b]++, p22[(10*b)+c]++, p23[(10*a)+c]++;
        p33[(100*a)+(10*b)+c]++;
    }
    cout << counter;

    return 0;
}