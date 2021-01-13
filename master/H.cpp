#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int x,num,querys;
	cin>>num>>querys;
	vector <int> vec;
	for(int i=0; i<num; i++)
	{
		cin>>x;
		vec.push_back(x);
	}
	sort(vec.begin(),vec.end());
	for(int i=0; i<querys; i++)
	{
		cin>>x;
		long long suma=0;
		
		for(int j=0; j<vec.size(); j++)
		{
			int busca= x-vec[j];

			auto it=lower_bound(vec.begin(),vec.end(), busca);
			
			if(it==vec.end())
				it--;
			else
			{
				if(*it!=busca)
					it--;
			}
			int mas=it-vec.begin();
			//cout<<"  "<<mas<<endl;
			mas-=j;
			//cout<<"   "<<mas<<endl;
			if(mas>0)
			{
				suma+=mas;
			}
		}
		//cout<<i<<endl;
		cout<<suma<<endl;
	}
}