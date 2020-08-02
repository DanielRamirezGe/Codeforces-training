#include <bits/stdc++.h>
using namespace std;
#define maxi_cam 602
#define maxi_nigth 302
#define inf 9999999
#define max_suma 2
typedef long long ll;
int res[maxi_cam][maxi_nigth];
int n, k;
ll acu[maxi_cam];
vector <int> vec;
int dp(int inicio, int fin, int noche)
{

	if(res[inicio][noche]!=-1)
		return res[inicio][noche];
	if(fin==vec.size()-1)
 			return acu[fin]-acu[inicio];
	if(noche==k)
		return acu[n+1]-acu[inicio];
	
	int no=dp(inicio, fin+1, noche);
	int yes=dp(fin, fin+1, noche+1);
	int tomado=acu[fin]-acu[inicio];
	return res[inicio][noche]=min(max(yes, tomado), no);
}
int main()
{
	int aux;
	while(cin>>n>>k)
	{
		vec.clear();
		int suma=0;
		vec.push_back(0);
		for(int i=0; i<=n;  i++)
		{
			cin>>aux;	
			acu[i+1]=acu[i]+aux;
			vec.push_back(aux);	
		}
		memset(res, -1, sizeof(res));
		aux = dp(0,1,0);
		cout<<aux<<endl;

	}
}