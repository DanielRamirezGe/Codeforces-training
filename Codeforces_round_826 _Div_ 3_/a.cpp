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
        string a,b;
        cin>>a>>b;
        int x1=0; 
        int x2=0;
        char ax;
        char bx;
        for(int j=0; j<a.size(); j++){
            if(a[j]!= 'X'){
                ax=a[j];
            }
            else{
                x1++;
            }
        }
        for(int j=0; j<b.size(); j++){
            if(b[j]!= 'X'){
                bx=b[j];
            }
            else{
                x2++;
            }
        }
        if(ax== 'S'){
            if(bx== 'M' || bx == 'L'){
                cout<<"<"<<endl;
            }
            else if(x1<x2){
                cout<<">"<<endl;
            }
            else if(x1==x2){
                cout<<"="<<endl;
            }
            else{
                cout<<"<"<<endl;
            }
        }
        
        if(ax== 'M'){
            if(bx== 'L' ){
                cout<<"<"<<endl;
            }else if(bx == 'S'){
                cout<<">"<<endl;
            }
            else if(x1<x2){
                cout<<"<"<<endl;
            }
            else if(x1==x2){
                cout<<"="<<endl;
            }
            else{
                cout<<">"<<endl;
            }
        }
        
        if(ax== 'L'){
            if(bx== 'S' || bx == 'M'){
                cout<<">"<<endl;
            }
            else if(x1<x2){
                cout<<"<"<<endl;
            }
            else if(x1==x2){
                cout<<"="<<endl;
            }
            else{
                cout<<">"<<endl;
            }
        }
    }

    return 0;
}
