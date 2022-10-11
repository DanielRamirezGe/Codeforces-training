#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> sum;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        vector <int> aux;
        string x;
        cin>>x;
        //cout<<" x: "<<x<<endl;
        for(int m=0; m<x.size(); m++){
            aux.push_back(x[m]- '0');
        }
        
        sum.push_back(aux);
    }
    vector <int> renglonSuma;
    vector <int> columnaSuma;
    for(int i=0; i<n; i++){
        int suma =0;
        for(int j=0; j<n; j++){
            suma += sum[i][j];
        }
        renglonSuma.push_back(suma);
    }
    for(int i=0; i<n; i++){
        int suma =0;
        for(int j=0; j<n; j++){
            suma += sum[j][i];
        }
        columnaSuma.push_back(suma);
    }
    int valido = 0;
    bool columnaValidacion = false;
    bool regVal = false;
    string ans = "";
    
    for(int i=0; i<columnaSuma.size(); i++){
        int sum = 0;
        sum += n-columnaSuma[i];
        for(int j=0; j<columnaSuma.size(); j++){
            if(j!=i){
                sum += columnaSuma[j];
            }
        }
        if(sum <= n){
            columnaValidacion = true;
            ans = "|";
        }
    }
    
    for(int i=0; i<renglonSuma.size(); i++){
        int sum = 0;
        sum += n-renglonSuma[i];
        for(int j=0; j<renglonSuma.size(); j++){
            if(j!=i){
                sum += renglonSuma[j];
            }
        }
        if(sum <=n){
            regVal = true;
            ans = "-";
        }
    }
    
    if(columnaValidacion && !regVal){
        cout<<"|"<<endl;
    }
    else if(!columnaValidacion && regVal){
        cout<<"-"<<endl;
    }else{
        cout<<"+"<<endl;
    }
    
    
}
