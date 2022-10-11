/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> sum;
    for(int i=99; i<100000; i+=100){
        sum.push_back(i);
    }
    int n;
    cin>>n;
    int ans = 99;
    int mens = abs(n-99);
    for(int i=0; i<sum.size(); i++){
        if(abs(n-sum[i]) <= mens){
            ans=sum[i];
            mens=abs(n-sum[i]);
        }
    }
    cout<<ans<<endl;
    
}
