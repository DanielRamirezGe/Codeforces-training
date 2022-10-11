#include <bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int a, b;
        cin>>a>>b;
        if(a<b){
            int c=b;
            b=a;
            a=c;
        }
        if(a==1 && b==1){
            cout<<0<<endl;
        }
        else{
            cout<<(a-1)+(b-1)+b<<endl;
        }
    }
}