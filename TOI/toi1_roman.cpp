#include <bits/stdc++.h>

using namespace std;
int i=0, v=0, x=0, l=0, c=0;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int j;
    cin >> j;
    for(int y=1; y<=j; y++){
        int n=y;
        while(n>0){
            if(n>=100){
                n-=100;
                c++;
            }
            else if(n>=90){
                n-=90;
                c++, x++;
            }
            else if(n>=80){
                n-=80;
                l++, x+=3; 
            }
            else if(n>=70){
                n-=70;
                l++, x+=2;
            }
            else if(n>=60){
                n-=60;
                l++, x++;
            }
            else if(n>=50){
                n-=50;
                l++;
            }
            else if(n>=40){
                n-=40;
                l++, x++;
            }
            else if(n>=30){
                n-=30;
                x+=3;
            }
            else if(n>=20){
                n-=20;
                x+=2;
            }
            else if(n>=10){
                n-=10;
                x++;
            }
            else if(n==9){
                n-=9;
                x++, i++;
            }
            else if(n==8){
                n-=8;
                v++, i+=3;
            }
            else if(n==7){
                n-=7;
                v++, i+=2;
            }
            else if(n==6){
                n-=6;
                v++, i++;
            }
            else if(n==5){
                n-=5;
                v++;
            }
            else if(n==4){
                n-=4;
                v++, i++;
            }
            else if(n==3){
                n-=3;
                i+=3;
            }
            else if(n==2){
                n-=9;
                i+=2;
            }
            else if(n==1){
                n-=1;
                i++;
            }
        }
    }

    cout << i << " " << v << " " << x << " " << l << " " << c;

    return 0;
}