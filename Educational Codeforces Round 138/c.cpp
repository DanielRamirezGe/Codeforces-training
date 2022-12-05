
#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long cases;
   cin>>cases;
   for(long long index=1; index<=cases; index++){
       //cout<<index<<"  __ "<<cases<<endl;
      int n;
      vector<int> vec, aux;
      cin>>n;
      for(int i=0; i<n; i++){
          int a;
          cin>>a;
          vec.push_back(a);
          aux.push_back(a);
      }
      bool ban = true;
      int k;
      for(int j=1 ; j<= n; j++){
          for(int i=0; i<n; i++){
              vec[i] = aux[i];
          }
          map<int,int> map;
          k=j;
          int turn=1;
          while( turn <= k ){
            int gran = 0;
            int index = -1;
            //cout<<"turn "<<turn<<"  "<<k<<endl;
            for(int i=0; i<n; i++){
                 //cout<<i<<" "<<map[i]<<" "<<vec[i]<<" "<<k-turn +1<<" "<< gran<<endl;
                if( map[i] == 0 && vec[i] <= k-turn +1  && gran < vec[i]){
                    gran = vec[i];
                    index = i;
                }
            }
            //cout<<index<<" "<<gran<<endl;
            if(index != -1){
                map[index] ++;
            }
            else{
                ban = false;
                break;
            }
            long long min = 100000000000;
            int indexEli = -1;
            for(int i=0; i<n; i++){
                if( map[i]==0 && min > vec[i]){
                    min = vec[i];
                    indexEli = i;
                }
            }
            if(indexEli!= -1)
            vec[indexEli] +=  k-turn +1;
            turn ++;
            
          }
          if(!ban){
              break;
          }
      }
      
      if(ban){
          cout<<k<<endl;
      }else
      
      cout<<k-1<<endl;
      //cout<<index<<"  __ "<<cases<<endl;
      
      
   }
}
