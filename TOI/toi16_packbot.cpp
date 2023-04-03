#include <bits/stdc++.h>

using namespace std;

int precedence(char op){
    if(op=='3') return 3;
    if(op=='2') return 2;
    if(op=='1') return 1;
    return 0;
}

int isOp(char sth){
    if(sth=='3' || sth=='2' || sth=='1' || sth=='[' || sth==']') return 1;
    return 0;
}

int calc(int x, int y, char op){
    if(op=='1') return (x+y)*104/100;
    if(op=='2') return (x+y)*108/100;
    if(op=='3') return (x+y)*116/100;
    return 0;
}

string q, postfix;
stack<int> st;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> q;
    for(auto c:q){
        if(!isOp(c)) postfix+=c;
        else if(c=='[') st.push(c);
        else if(c==']'){
            while(st.top()!='['){
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(c)<=precedence(st.top())){
                postfix+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix+=st.top();
        st.pop();
    }
    
    //cout << postfix;

    for(int i=0; i<postfix.size(); i++){
        if(!isOp(postfix[i]))st.push(20);
        else{
            int num1=st.top();
            st.pop();
            int num2=st.top();
            st.pop();
            st.push(calc(num1, num2, postfix[i]));
        }
    }

    cout << st.top();

    return 0;
}