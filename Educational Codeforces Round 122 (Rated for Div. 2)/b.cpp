#include <iostream>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases){
        cases--;
        string cad;
        cin>>cad;
        int cero=0, uno=0;
        for(int i=0; i<cad.size(); i++){
            if(cad[i]=='0'){
                cero++;
            }
            else{
                uno++;
            }
        }
        if(cad.size()==1 || cad.size()==2){
            cout<<0<<endl;
        }
        else if(cero==0 || uno==0){
            cout<<0<<endl;
        }
        else if(uno>cero){
            cout<<cero<<endl;
        }
        else if(cero>uno){
            cout<<uno<<endl;
        }
        else{
            cout<<cero-1<<endl;
        }
    }
}