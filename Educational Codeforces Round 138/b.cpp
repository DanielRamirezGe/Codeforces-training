
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int cases;
   cin>>cases;
   for(int i=0; i<cases; i++){
       vector<pair<long long,long long>> mon, aux;
       int n;
       cin>>n;
       long long sum=0;
       for(int i=0; i<n; i++){
           long long a;
           cin>>a;
           mon.push_back({a,0});
       }
       for(int i=0; i<n; i++){
           long long b;
           cin>>b;
           mon[i] = {mon[i].first, b};
       }
       for(int i=0; i<n; i++){
           if(mon[i].second == 0){
               sum += mon[i].first;
           }
           else{
               aux.push_back(mon[i]);
           }
       }
       int izq=0, der=aux.size()-1;
       while(izq <= der){
           if(izq == der ){
                
               sum += aux[izq].first;
               izq ++;
               der --;
           }
           else if(aux[izq].second < aux[der].second){
               sum += aux[izq].first;
               aux[izq+1].first += aux[izq].second;
               izq ++;
           }
           else{
               sum += aux[der].first;
               aux[der-1].first += aux[der].second;
               der --;
           }
          // cout<<"sum  "<<sum<<endl;
       }
       cout<<sum<<endl;
   }
}
