#include <bits/stdc++.h>
using namespace std; 
int main()
{
	vector<int> vec;
	int n,query,aux,res;
	cin>>n>>query;
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	sort(vec.begin(),vec.end());
	//auto m= lower_bound(vec.begin(),vec.end(),8);
	//auto po=lower_bound(vec.begin(),vec.end(),12);
	//cout<<*m<<" "<<*po<<endl;

	for(int i=0; i<query; i++)
	{
		cin>>aux;
		long long sum=0;
		for(int i=0; i<n ; i++)
		{
			res=aux-vec[i];

			auto it= lower_bound(vec.begin(),vec.end(),res);
			//cout<<vec[i]<<"  "<<res<<"  "<<*it<<endl;
			
			if(it==vec.end())
				it--; 
			else
				if(*it>res)
					it--;	
			int pos= it-vec.begin();
			//cout<<pos<<" "<<i<<endl;
			if(pos<=i)
				break;
			sum+=pos-i;
		}
		cout<<sum<<endl;
	}					
}