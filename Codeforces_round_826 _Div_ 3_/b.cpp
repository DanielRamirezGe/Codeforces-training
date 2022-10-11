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
    for(int i =0 ; i<cases; i++){
        int n;
        cin>>n;
        if(n ==3){
            cout<<"-1"<<endl;
        }
        else if(n%2){
                cout<<n<<" "<<n-1<<" ";
                for(int  j=1 ; j<= n-2; j++){
                    cout<<j;
                    if(j != n-2){
                        cout<<" ";
                    }
                    else{
                        cout<<endl;
                    }
                }
            }
            else{
                for(int  j=n ; j>=1; j--){
                    cout<<j;
                    if(j!= 1){
                        cout<<" ";
                    }
                    else{
                        cout<<endl;
                    }
                }
            }
        
    }

    return 0;
}
