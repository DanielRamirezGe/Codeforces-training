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
        int a,b;
        cin>>a>>b;
        int ans = 0;
        for(long long j=a ; j<=b; j++){
            string cad="";
            bool ban = 0;
            for(int move= 0 ; move<30 ; move++){
               
                    cad.push_back(j & 1<<move ? '1' : '0' );
                    if(1<<move > j){
                        break;
                    }
                
            }
            if( cad[cad.size()-1]=='0'){
                cad.pop_back();
            }
            int izq = 0;
            int der = cad.size()-1;
            bool pal = true;
            while(izq < der){
                if(cad[izq] != cad[der]){
                    pal= false;
                    break;
                    
                }
                izq++;
                der--;
            }
            if(pal && j!=0)
                ans ++;
        
        }
        cout<<ans<<endl;
        
        
    }

    return 0;
}
