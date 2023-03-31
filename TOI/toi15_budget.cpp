#include <bits/stdc++.h>

using namespace std;
int B, E, s, t, l, r, P, C, D;

struct Data{
    int s, t, l, r;

    bool operator <(const Data&d2) const{
        if(r==d2.r) return d2.l<l;
        return r<d2.r;
    }
};

priority_queue<Data> pq;
vector<pair<int, int>> price;
int ans;
int parent[3002];

int findpa(int x){
    if(parent[x]==x) return x;
    return parent[x]=findpa(parent[x]);
}

int find(int lh){
	int idx=0;
	int minp=INT_MAX;
	for(int i=0; i<P; i++){
        if(price[i].second<minp&&price[i].first>=lh){
            minp=price[i].second;
            idx=i;
        }
	}
	return idx;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> B >> E;
    for(int i=0; i<B; i++)parent[i]=i;
    for(int i=0; i<E; i++){
        cin >> s >> t >> l >> r;
        if(r==1) parent[findpa(s)]=parent[findpa(t)];
        else pq.push({s, t, l, r});
    }

    cin >> P;
    for(int i=0; i<P; i++){
        cin >> C >> D;
        price.push_back({C, D});
    }
    sort(price.begin(), price.end());

    while(!pq.empty()){
        int u=pq.top().s, v=pq.top().t, w=pq.top().l, r=pq.top().r;
        pq.pop();
        if(findpa(u)!=findpa(v)){
            ans+=price[find(w)].second;
            parent[findpa(v)]=parent[findpa(u)];
        }
    }

    cout << ans;

    return 0;
}

/*
kruskal ก่อน priority กับถนนที่มีหลังคาอยู่แล้วก่อน
ไล่ parent หาคุ้มสุด
*/