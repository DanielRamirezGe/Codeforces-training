#include <bits/stdc++.h>
using namespace std;
#define maxi 5005
vector <int> mat [maxi];
int dis[maxi];
int dis_dos[maxi];
int dis_tres[maxi];

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0; i<maxi; i++)
			mat[i].clear();
		for(int i=1; i<=n; i++)
		{
			int k,aux;
			cin>>k;
			for(int j=0; j<k; j++)
			{
				cin>>aux;
				mat[i].push_back(aux);
				mat[aux].push_back(i);
			
			}
		}
		queue<int> cola;
		cola.push(1);
		memset(dis, -1, sizeof(dis));
		memset(dis_dos, -1, sizeof(dis_dos));
		memset(dis_tres, -1, sizeof(dis_tres));
		
		dis[1]=0;
		while(!cola.empty())
		{
			for(auto x: mat[cola.front()])
			{
				if(dis[x]==-1)
				{
					dis[x]=dis[cola.front()]+1;
					cola.push(x);
				}
			}
			cola.pop();
		}
		int maxim=0;
		int nodo=0;
		vector<int> lo_feo;
		for(int i=1; i<=n; i++)
		{
			if(dis[i]>maxim)
			{
				lo_feo.clear();
				maxim=dis[i];
				lo_feo.push_back(i);
				nodo=i;
			}
			else
				if(dis[i]==maxim)
					lo_feo.push_back(i);
		}
		dis_dos[nodo]=0;
		cola.push(nodo);
		while(!cola.empty())
		{
			for(auto x: mat[cola.front()])
			if(dis_dos[x]==-1)
			{
				dis_dos[x]=dis_dos[cola.front()]+1;
				cola.push(x);
			}
			cola.pop();
		}
		
		
		int maxi_dis=0;
		int otro=0;
		for(int i=1; i<=n; i++)
			if(maxi_dis<dis_dos[i])
			{
				maxi_dis=dis_dos[i];
				otro=i;
			}

		cola.push(otro);
		dis_tres[otro]=0;
		while(!cola.empty()){
			for(auto x: mat[cola.front()])
				if(dis_tres[x]==-1)
				{
					dis_tres[x]=dis_tres[cola.front()]+1;
					cola.push(x);
				}
			cola.pop();
		}


		set<int> feo;
		vector <int> best;
		//cout<<"    "<<maxi_dis<<endl;
		for(int i=1; i<=n; i++)
		{
			if(dis_dos[i]==maxi_dis)
				feo.insert(i);

			if(maxi_dis%2==0)
			{
				if(dis_dos[i]==maxi_dis/2 and dis_tres[i]==maxi_dis/2)
					best.push_back(i);
			}
			else{
				if(dis_dos[i]==maxi_dis/2)
					if(dis_tres[i]==(maxi_dis/2)+1)
						best.push_back(i);
				if(dis_dos[i]==(maxi_dis/2)+1)
					if(dis_tres[i]==maxi_dis/2)
						best.push_back(i);	



			}
		
		
		}
		
		for(int i=0; i<lo_feo.size(); i++)
			feo.insert(lo_feo[i]);
		
		sort(best.begin(), best.end());
		cout<<"Best Roots  : ";
		for(int i=0; i<best.size(); i++)
		{
			cout<<best[i];
			if(i!=best.size()-1)
				cout<<" ";
			else
				cout<<endl;
		}
		cout<<"Worst Roots : ";
		for(auto i=feo.begin(); i!=feo.end(); i++)
		{
			cout<<*i;
			auto aux=i;
			aux++;
			if(aux!=feo.end())
				cout<<" ";
			else
				cout<<endl;
		}


		
	}
}