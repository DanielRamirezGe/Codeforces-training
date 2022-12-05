/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    int a,b,c;
    for(int i=0; i<cases; i++){
    cin>>a>>b>>c;
    if(a+b == c){
        cout<<"YES"<<endl;
    }
    else if(a+c == b){
        cout<<"YES"<<endl;
    }
    else if(b+c == a){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
}
