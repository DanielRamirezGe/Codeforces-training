#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n,tot;
	cin>>cases;
	char l,g;
	int d;
	for(int i=0; i<cases; i++)
	{
		cin>>n>>tot;
		vector<pair<int,int> > vec;
		for(int i=0; i<n; i++)
		{
			cin>>l>>g>>d;
			
			if(l=='B')
				vec.push_back({d,1});
			else
				vec.push_back({d,2});
		}
		vector <int> dos;
		vector <int> aux;
		dos.push_back(0);
		vec.push_back({tot,1});
		int ant=0;
		int max=0;
		for(int i=0; i<vec.size(); i++)
		{
			//cout<<vec[i].first<<" "<<vec[i].second<<endl;
			if(vec[i].second==2)
			{

				aux.clear();
				while(vec[i].second==2 and i<vec.size())
				{

					aux.push_back(vec[i].first);
					i++;
				}
				
				for(int j=0; j<aux.size(); j++)
				{
					if(j%2==0)
					{
						//cout<<"no pongo: "<<aux[j]<<endl;
						int m=aux[j]-ant;
						if(m>max)
							max=m;
						ant=aux[j];
					}
					else
					{
						dos.push_back(aux[j]);
					}
				}
				int m=vec[i].first-ant;
				if(m>max)
					max=m;
				if(i<vec.size())
				{
					dos.push_back(vec[i].first);
					ant=vec[i].first;
				}
			}
			else
			{
				int m=vec[i].first-ant;
				if(m>max)
					max=m;
				ant=vec[i].first;
				dos.push_back(vec[i].first);
			}
		}
		ant=tot;
		int po=i;
		//if(po==52)
		//	cout<<n<<" "<<tot<<endl;
		for(int i=dos.size()-1; i>=0; i-- )
		{
			//if(po==52)
			//cout<<endl<<ant<<" "<<dos[i]<<" "<<ant-dos[i]<<endl;
			if(max<ant-dos[i])
				max=ant-dos[i];
			ant=dos[i];
		}
		cout<<"Case "<<i+1<<": "<<max<<endl;
	}

}