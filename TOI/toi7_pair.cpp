#include <bits/stdc++.h>

using namespace std;
pair<int, int> pr[100001];
double total=0;
void merge_s(int l, int r){
    if(l==r) return ;

    int m=(l+r)/2;
    merge_s(l, m);
    merge_s(m+1, r);

    pair<long long, long long> arrL[m-l+1];
    pair<long long, long long> arrR[r-m];

    for(int i=0; i<m-l+1; i++) arrL[i] = pr[l+i];
    for(int i=0; i<r-m; i++) arrR[i] = pr[m+1+i];

    long long qsR[m-l+2];
    qsR[0]=0;
    for(int i=1; i<=r-m; i++){
        qsR[i] = qsR[i-1]+arrR[i-1].first;
    }

    int i=0, j=0, idx=l;
    while(i<m-l+1 && j<r-m) {
        if(arrL[i].second < arrR[j].second) {
            pr[idx] = arrL[i];
            total += (qsR[r-m]-qsR[j])+((r-m-j)*arrL[i].first);
            idx++, i++;
        }else {
            pr[idx] = arrR[j];
            idx++, j++;
        }
    }
    while(i < m-l+1){
        pr[idx] = arrL[i];
        idx++, i++;
    }
    while(j <r-m){
        pr[idx] = arrR[j];
        idx++, j++;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> pr[i].first >> pr[i].second;
    }

    sort(pr, pr+n);
    reverse(pr, pr+n);
    merge_s(0, n-1);

    printf("%.0lf", total);

    //display
    // for(int j=0; j<n; j++){
    //     cout << pr[j].first << " " << pr[j].second << "\n";
    // }


    return 0;
}