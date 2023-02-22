#include <bits/stdc++.h>

using namespace std;
map<int, int> mpp;
queue<int> que_class[11];
queue<int> line; //check ยังมีห้องไหนบ้าง เรียงยังไง
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int nc, ns, key, val, id;
    cin >> nc >> ns;
    for(int i=0; i<ns; i++){
        cin >> val >> key;
        mpp[key] = val;
    }

    string check;
    do{
        cin >> check;
        if(check=="E"){
            cin >> id;
            if(que_class[mpp[id]].empty()) line.push(mpp[id]);
            que_class[mpp[id]].push(id);
        }
        if(check=="D"){
            if(line.empty()) cout << "empty" << "\n";
            else{
                cout << que_class[line.front()].front() << "\n";
                que_class[line.front()].pop();
                if(que_class[line.front()].empty()) line.pop();
            }
        }
    }while(check!="X");

    cout << "0";

    return 0;
}

/*
ถ้าแถวว่างเอาใส่เลย ว่าง = ไม่มีชั้นนั้น
ใส่แยกชั้น

เอาออก
เอาออกตามชั้นที่ใส่ลำดับไว้
เอาตัวแรกของชั้นนั้นมา
เอาตัวแรกของชั้นนั้นออก
ถ้าชั้นนั้นหมด
เอาออกจากแถว
*/