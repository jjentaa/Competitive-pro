#include <bits/stdc++.h>

using namespace std;

struct Store{
    int x, y, z, m, k, c;
};

int powsq(int t) {return t*t;}

int n, sx, sy, sz, ms, minn=INT_MAX;
bool visitt[21];
Store store[21];

void solve(int price, int am, int ak, int ac, int preX, int preY, int preZ){
    if(price > minn) return ;
    if(am>=n && ak>=n && ac>=n) minn=min(minn, price);

    for(int i=0; i<ms; i++){
        if(visitt[i]) continue;
        visitt[i]=true;
        solve(price+powsq(store[i].x-preX)+powsq(store[i].y-preY)+powsq(store[i].z-preZ), am+store[i].m, ak+store[i].k, ac+store[i].c, store[i].x, store[i].y, store[i].z);
        visitt[i]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> sx >> sy >> sz >> ms;
    for(int i=0; i<ms; i++) cin >> store[i].x >> store[i].y >> store[i].z >> store[i].m >> store[i].k >> store[i].c;
    solve(0, 0, 0, 0, sx, sy, sz);

    cout << minn;

    return 0;
}