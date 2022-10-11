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
    for(int i=0; i<cases; i++){
       int a;
       cin>>a;
       for(int i=a-2; i>1; i--){
            cout<<i;
            cout<<" ";
       }
       cout<<1<<" "<<a-1<<" "<<a<<endl;
    }

    return 0;
}
