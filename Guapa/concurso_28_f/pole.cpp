#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int n,num,pos;
    int i;
    int vacio=0;
    vector<pair<int,int>>vec;   //aquí marca el problema.
    vector<int> fin;
    while(cin>>n and n!=0)
    {
        vec.clear();
        fin.clear();
        fin.assign(n+1,0);
        for(i=1;i<=n;i++)
        {
            cin>>num>>pos;
            vec.push_back({num,pos});
        }
        bool ban=0;
        for(i=0;i<vec.size();i++)
        {
            int a=(i+1)+vec[i].second;
            if(a<=n and 0<a)
            {
                if(fin[a]==vacio)
                    fin[a]=vec[i].first;
                
                else
                {
                    ban=1;
                    cout<<"-1";
                    break;
                }
                
                             
            }
            else
            {
                ban=1;
                cout<<"-1";
                break;  
            }
        }
        if(!ban)
        for(i=1;i<fin.size();i++)
        {
          cout<<fin[i];
          if(i!=vec.size())
            cout<<" ";
        }
        cout<<endl;
    }

}

