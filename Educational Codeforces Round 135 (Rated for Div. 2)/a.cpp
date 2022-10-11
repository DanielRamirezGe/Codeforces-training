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
        int n;
        cin>>n;
        int max=0;
        int ans=0;
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            if(a>=max){
                max = a;
                ans = j+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
