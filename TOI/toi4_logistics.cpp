#include <bits/stdc++.h>

using namespace std;

struct ANS{
    char u, v;
    double w;
};

map<char, vector<pair<char, double> > > g;
vector<ANS> solution;
double total;

void dfs(char e, char pa){
    vector<double> data;
    char nextNode;
    int isParent=1;
    for(auto [v, w]: g[e]){
        if(v==pa) continue;
        isParent=0;
        data.push_back(w);
        nextNode=v;
    }

    if(isParent){
        cout << "broken";
        exit(0);
    }

    sort(data.begin(), data.end());

    if(data.size()%2==0){
        double med=(data[data.size()/2]+data[(data.size()/2) -1])/2.0;
        total+=med;
        solution.push_back({e, nextNode, med});
    }
    else{
        double med=data[data.size()/2];
        total+=med;
        solution.push_back({e, nextNode, med});
    }

    if(nextNode=='Y') return ;

    dfs(nextNode, e);
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char u, v;
        float w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs('X', 'J');
    for(auto [u, v, w]:solution){
        printf("%c %c %.1lf\n", u, v, w);
    }
    printf("%.1lf", total);
    

    return 0;
}

/*
6
X a 1
a b 4
b a 1
b Y 3
b Y 2
Y b 6
*/
/*
3
X a 2
c b 3
b Y 3
*/
/*
5
q Y 3
X a 1
a b 2
t b 4
q t 5
*/