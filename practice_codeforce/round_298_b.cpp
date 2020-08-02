#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	vector<int> vec;
	int n, aux;
	for(int i=0; i<cases; i++)
	{
		cin>>n;
		vec.clear();
		for(int j=0; j<n; j++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		bool arr[vec.size()];
		memset(arr, 0, sizeof(arr));
		
		for(int busca=1; busca<n; busca++)
		{
			int p=0;
			for(; p<vec.size(); p++)
			{
				if(busca==vec[p])
					break;
			}
			int it=p-1;
			if(it>=0)
			{
				//cout<<it<<" "<<busca<<" "<<arr[it]<<endl;
				while(it>=0 and !arr[it] and vec[it]>vec[it+1])
				{
					//cout<<"   "<<vec[it]<<" "<<vec[it+1]<<endl;
					int c=vec[it];
					vec[it]=vec[it+1];
					vec[it+1]=c;
					arr[it]=1;
					it--;
					//cout<<"   "<<vec[it]<<" "<<vec[it+1]<<endl<<endl;
				}
			}
		}
		for(int i=0; i<vec.size(); i++)
			if(i!=vec.size()-1)
				cout<<vec[i]<<" ";
			else
				cout<<vec[i]<<endl;
	}
}