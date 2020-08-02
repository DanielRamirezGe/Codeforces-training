#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases,n,k;
    cin>>cases;
    long long min,aux,max;
    for(int i=0; i<cases; i++)
    {
        cin>>n>>k;
        for(int j=0; j<n; j++)
        {
            cin>>aux;
            if(j==0)
            {
                if      (aux-k>=0)
                    min=aux-k;
                else
                    min=0;
                max=aux+k;
                
            }
            else
            {
                if(aux-k>min)
                    min=aux-k;
                if(aux+k<max)
                    max=aux+k;
            }
        }
        if(min>max)
            cout<<-1<<endl;
        else
            cout<<max<<endl;
        
    }
}
