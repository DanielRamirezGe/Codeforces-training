#include <bits/stdc++.h>
using namespace std;
int main()
{
    string cad;
    string nuevo;
    cin>>cad;
    int k;
    cin>>k;
    int tot=0;
    bool ban=0;
    for(int i=0; i<cad.size(); i++)
    {
        if(cad[i]=='*' or cad[i]=='?')
        {
            if(cad[i]=='*')
                ban=1;
            tot++;
        }
    }
    if(cad.size()-(tot*2) >k or ((cad.size()-tot<k) and ban==0))
        cout<<"Impossible"<<endl;
    else
    {
        
        if(ban)
        {
            int x=cad.size()-((tot)*2);
            int suma=k-x;
            bool para;
            if(suma>0)
             para=1;
            else
                para=0;
            for(int i=0; i<cad.size(); i++)
            {
                if(cad[i]=='*' and para)
                {
                    while(suma>1)
                    {
                        nuevo.push_back(nuevo[nuevo.size()-1]);
                        suma--;
                    }
                    para=0;
                }
                else
                {
                    if(cad[i]=='*' or cad[i]=='?')
                        nuevo.pop_back();
                    else
                    {
                        nuevo.push_back(cad[i]);
                    }
                }                    
            }
        }
        else
        {
            int x=cad.size()-(tot*2);
            int suma=k-x;
            for(int i=0; i<cad.size(); i++)
            {
                if(cad[i]=='?' and suma)
                {
                    suma--;
                }
                else
                {
                    if(cad[i]=='?')
                        nuevo.pop_back();
                    else
                        nuevo.push_back(cad[i]);
                }
            }
        }
         cout<<nuevo<<endl;
    }
   
}
