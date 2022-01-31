#include <iostream>
#include <vector>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int n;
        cin>>n;
        n--;
        if(n%2){
            vector<int> ans;
            for(int j= n-1 -2;  j>= 0; j-=2){
                ans.push_back(j);
            }
            ans.push_back(n-1);
            ans.push_back(n);
            for(int j=1; j<n; j+=2){
                ans.push_back(j);
            }
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i];
                if(i!=ans.size()-1){
                    cout<<" ";
                }
                else{
                    cout<<endl;
                }
            }
        }
        else{
            int menPar =0;
            int mayPar = n;
            int menNon = 1;
            int mayNon = n-1;
            vector <int> ans;
            bool isPar=true;
            for(int j=0; j<n/2; j++){
                if(isPar){
                    ans.push_back(mayPar);
                    ans.push_back(menPar);
                    mayPar -= 2;
                    menPar += 2;
                    isPar=false;
                }
                else{
                    ans.push_back(mayNon);
                    ans.push_back(menNon);
                    mayNon -=2;
                    menNon +=2;
                    isPar=true;
                }
            }
            if( (n/2) %2 ){
                ans.push_back(menNon);
            }
            else{
                ans.push_back(menPar);
            }
            for(int j=ans.size()-1; j>=0; j--){
                cout<<ans[j];
                if(j!=0){
                    cout<<" ";
                }
                else{
                    cout<<endl;
                }
            }
        }
    }
}