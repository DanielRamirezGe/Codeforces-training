#include <bits/stdc++.h>
using namespace std;
#define inf 9999999
#define max_pre 100000
#define max_bit 1500
typedef pair<pair<int,int>, pair<int,int> > iii;
int escenarios, aux, a ,b,total , en;
vector<iii> vec;
set <pair<int,int>> buscar;
int OK;
int respuesta[max_pre][max_bit];

int f(int indicador, int bit)
{
	if(indicador==total)
	{
		if(bit==OK)
			return 0;
		else
			return -inf;
	}
	int &res=respuesta[indicador][bit];
	if(res)
		return res;
	int fin=vec[indicador].first.second;
	auto it=buscar.lower_bound({fin, indicador});
	if(it!=buscar.end())
		return res=max(f(it->second, bit | (1<<vec[indicador].second.second))+vec[indicador].second.first, f(indicador+1, bit) ); 	
	else
		return res=f(indicador+1, bit) ;
}

int main()
{
	memset(respuesta, 0, sizeof(respuesta));
	scanf("%d",&escenarios);
	OK=(1<<escenarios)-1;
	for(int i=0; i<escenarios; i++)
	{
		scanf("%d",&aux);
		for(int j=0; j<aux; j++)
		{
			scanf("%d %d %d",&a,&b,&en);
			vec.push_back({{a,b},{en, i}});
		}
	}
	sort(vec.begin(), vec.end());
	total=vec.size();

	for(int i=0; i< total; i++)
		buscar.insert({vec[i].first.first, i});
	
	int tot=f(0,0);

	cout<<tot<<endl;


}

