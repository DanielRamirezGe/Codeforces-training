#include <bits/stdc++.h>
using namespace std;
int main()
{
    string cad;
    string res;
    cin>>cad;
    for(int i=0; i<cad.size(); i++)
    {
        if(cad[i]>='0' and cad[i]<='9')
            res.push_back(cad[i]);
        else
            break;
    }
    if(res.size()==0)
        cout<<-1<<endl;
    else
        cout<<res<<endl;
}