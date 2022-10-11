#include <bits/stdc++.h>
using namespace std;
int main(){
   int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        long long n,k,b,s;
        cin>>n>>k>>b>>s;
        long long sup = s/k;
        long long inf = (s - ((n-1)*(k-1)))/k;
        //cout<<inf<<"  -   "<<sup<<"   "<<b<<"  "<<s<<"/"<<k<<endl;
        if(inf<=b && b<=sup){
            long long s_rem = s;
            long long take = 0;
            while( (s_rem - (k-1) >0) && (s_rem - (k-1))/k >= b ){
                take++;
                s_rem -= (k-1);
            }
            //cout<<"take: "<<take<<endl;
            cout<<s-(take*(k-1)) <<" ";
            for(int i=0; i<n-1; i++){
                if(i<take){
                    cout<<(k-1);
                }
                else{
                    cout<<0;
                }
                if(i!= (n-2)){
                    cout<<" ";
                }
                else{
                    cout<<endl;
                }
            }
            if(0 >= n-1 ){
                cout<<endl;
            }

        }
        else{
            cout<<-1<<endl;
        }
    }
}