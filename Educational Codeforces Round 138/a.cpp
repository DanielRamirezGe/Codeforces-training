/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
   int cases;
   cin>>cases;
   for(int i=0; i<cases; i++){
       int n,m;
       cin>>n>>m;
       map <int,int> ren, col;
       for(int i=0; i<m; i++){
           int a,b;
           cin>>a>>b;
           ren[a]++;
           col[b]++;
       }
       bool ans= false;
       
       for(int j=1; j<=n; j++){
           if(ren[j] == 0){
               ans = true;
           }
       }
       
       for(int j=1; j<=n; j++){
           if(col[j] == 0){
               ans = true;
           }
       }
       
       
       if(ans){
           cout<<"YES"<<endl;
       }
       else{
           cout<<"NO"<<endl;
       }
       
       
       
   }
}
