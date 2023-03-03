#include <bits/stdc++.h>

using namespace std;
string number1="", number2="";

char checker(string target){
    if(target==" _ | ||_|") return '0';
    if(target=="     |  |") return '1';
    if(target==" _  _||_ ") return '2';
    if(target==" _  _| _|") return '3';
    if(target=="   |_|  |") return '4';
    if(target==" _ |_  _|") return '5';
    if(target==" _ |_ |_|") return '6';
    if(target==" _   |  |") return '7';
    if(target==" _ |_||_|") return '8';
    if(target==" _ |_| _|") return '9';
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m1, m2;
    cin >> m1 >> m2;
    vector<string> num1(m1, ""), num2(m2, "");
    string sth;
    getline(cin, sth);
    for(int i=0; i<3; i++){
        int temp=0;
        string s;
        getline(cin, s);
        for(int j=0; j<s.size(); j++){
            if((j+1)%4 == 0){
                temp++;
                continue; // passing a space
            }
            num1[temp]+=s[j];
        }
    }

    for(int i=0; i<3; i++){
        int temp=0;
        string s;
        getline(cin, s);
        for(int j=0; j<s.size(); j++){
            if((j+1)%4 == 0){
                temp++;
                continue; // passing a space
            }
            num2[temp]+=s[j];
        }
    }

    for(int i=0; i<m1; i++){
        number1+=checker(num1[i]);
    }

    for(int i=0; i<m2; i++){
        number2+=checker(num2[i]);
    }
    long long ans = stoll(number1)+stoll(number2);
    cout << ans;

    return 0;
}