/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    int a,b,c;
    for(int i=0; i<cases; i++){
        int n;
        map<int,int> mapa;
        cin>>n;
        bool ans= true;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(mapa[x] !=0){
                ans=false;
            }
            mapa[x]++;
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
