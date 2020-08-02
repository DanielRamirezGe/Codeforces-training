#include <bits/stdc++.h>
using namespace std;
#define max_node 10
#define max_bit 1024
#define inf 99999999
pair<vector<int>,double> res[max_node][max_bit];
vector < pair< double, int>  > mat[max_node];
int padre[max_node];
int p_imp[max_node];
int ok;
pair<vector<int>,double> f(int nodo, int bit)
{
	if(bit==ok)
	{
		vector<int> po;
	
		
		return {po,0};
	}
	if(res[nodo][bit].second!=0)
		return res[nodo][bit];
	double tot=inf;
	vector <int> pi;
	for(auto a: mat[nodo])
	{
		int i=a.second;
		double d=a.first;
		if(!(bit & (1<<i)))
		{
			bit|=(1<<i);
			pair<vector<int>,double>  p = f(i, bit);
			bit-=(1<<i);
			if(d+p.second < tot)
			{ 
				pi.clear();
				pi.push_back(i);
				for(auto a: p.first)
					pi.push_back(a);
				tot=d+p.second;
			}
		}
	}
	return res[nodo][bit]={pi,tot};
}
double d(int a, int b,int c, int d)
{
	return sqrt(pow(a-c,2)+pow(b-d,2));
}

int main()
{
	int num;
	int con=1;
	int a,b;
	while(cin>>num and num!=0)
	{
		cout<<"**********************************************************\n";
		cout<<"Network #"<<con++<<endl;
		for(int i=0; i<max_node; i++)
			mat[i].clear();
		ok=(1<<num)-1;
		vector< pair<int,int>> vec;
		for(int i=0; i<num; i++)
		{
			cin>>a>>b;
			vec.push_back({a,b});
		}
		for(int i=0; i<num; i++ )
		{
			for(int j=0; j<num; j++)
			{
				double p=d(vec[i].first,vec[i].second,vec[j].first, vec[j].second);
				p+=16;
				mat[i].push_back({p,j});
			}
		}
		double imp=inf;
		pair<vector<int>,double>  ip;
		vector<int > popo;
		int po=0;
		int ini;
		for(int i=0; i<num; i++)
		{
			for(int i=0; i<max_node; i++)
				for(int j=0; j<max_bit; j++)
				{
					res[i][j].second=0;
					res[i][j].first.clear();
				}
			//res[max_node][max_bit];
			ip=f(i, 1<<i);
			if(ip.second<=imp)
			{
				
				imp=ip.second;
				
				popo.clear();
				popo.push_back(i);
				for(auto a: ip.first)
					popo.push_back(a);
			}
		}
	
		for(int i=1; i<popo.size(); i++)
		{
			cout<<"Cable requirement to connect ("<<vec[popo[i-1]].first<<","<<vec[popo[i-1]].second<<") to ("<<vec[popo[i]].first<<","<<vec[popo[i]].second<<") is ";printf("%.2lf feet.\n", mat[popo[i-1]][popo[i]].first);
		}
		/*while(p_imp[it]!=-1)
		{
			pq=padre[it];
			cout<<"Cable requirement to connect ("<<vec[it].first<<","<<vec[it].second<<") to ("<<vec[pq].first<<","<<vec[pq].second<<") is "<<mat[it][pq].first<<" feet.\n";
			it=padre[it];
		}*/
		cout<<"Number of feet of cable required is "; printf("%.2lf.\n",imp);

	}
}