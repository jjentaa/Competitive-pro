#include <bits/stdc++.h>

using namespace std;
string sth;
int letter[27];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> sth;
    for(int i=0; i<sth.size(); i++){
        letter[sth[i]-'A']++;
    }

    int lonep=-1; // odd freq
    for(int i=0; i<26; i++){
        if(letter[i]%2==1){
            if(lonep!=-1){
                // there are more than 1 lone pair
                cout << "NO SOLUTION";
                return 0;
            }
            else lonep=i;
        }
    }
    
    for(int i=0; i<26; i++){
        for(int j=0; j<letter[i]/2; j++){
            printf("%c", (char) i+'A');
        }
    }

    if(lonep!=-1){
        printf("%c", (char) lonep+'A');
    }

    for(int i=25; i>=0; i--){
        for(int j=0; j<letter[i]/2; j++){
            printf("%c", (char) i+'A');
        }
    }

    return 0;
}