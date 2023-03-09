#include <bits/stdc++.h>

using namespace std;
string s;
int solve(){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
        else if(st.empty()) return 0;
        else if(s[i]==')' && st.top()=='(') st.pop();
        else if(s[i]==']' && st.top()=='[') st.pop();
        else if(s[i]=='}' && st.top()=='{') st.pop();
        else return 0;
    }
    if(st.empty()) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        if(solve()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}