
#include <bits/stdc++.h>
using namespace std;
#define mx 1009
typedef long long ll;
typedef pair<ll,ll> ii;
vector < ii > uno,dos;
vector <int> mat[mx];
int dis[mx];

bool cross(ii p, ii q, ii r)
{ 
    ii piv1;
    ii piv2;
    piv1.first = p.first - q.first;
    piv1.second = p.second - q.second;
    
    piv2.first = q.first - r.first;
    piv2.second = q.second - r.second;
    ll val = piv1.first * piv2.second - piv2.first * piv1.second;
    //cout << val<<endl;
    if(val == 0)
        return true;
    return false;
    
    
}
bool onSegmet(ii p, ii q, ii r) //is q in [p-r]? p-q and q-r are collinear
{
    if(q.first <= max(p.first,r.first) and q.first >= min(p.first,r.first) and q.second <= max(p.second,r.second) and q.second >= min(p.second,r.second) and cross(p,q,r) )
    {
        return true;
    }
     return false;
}


void build()
{
    for(int i=0; i<uno.size(); i++)
    {

        for(int j=0; j<uno.size(); j++){
            if(i!=j)
            {
                ii a=uno[i];
                ii b=uno[j];
                bool ban=0;
                for(int h=0; h<dos.size(); h++){
                    ii c=dos[h];
                    if( onSegmet(a,c,b)/*pointOnLine(c, a, b)*/ )
                        ban=1;
                }
                for(int h=0; h<uno.size(); h++){
                    ii c=uno[h];
                    if(h!=i and h!=j and onSegmet(a,c,b)/*pointOnLine(c, a, b)*/ )
                        ban=1;
                }
                if(!ban)
                    mat[i].push_back(j);
            }
        }
    }
}   



int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        uno.push_back({a,b});

    }
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        dos.push_back({a,b});
        
    }

    build();
    memset(dis, -1, sizeof(dis));

    queue <int> cola;
    cola.push(0);
    dis[0]=0;
    while(!cola.empty()){
        int p=cola.front();
        cola.pop();
        for(auto x: mat[p]){
            if(dis[x]==-1){
                dis[x]=dis[p]+1;
                cola.push(x);
            }
        }
    }
    cout<<dis[n-1]<<endl;




}
