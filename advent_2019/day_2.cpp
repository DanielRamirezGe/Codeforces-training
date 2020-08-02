#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> vec;
	int num;
	char coma;
	cin>>num;
	
	
	vec.push_back(num);
	while(cin>>coma)
	{
		cin>>num;
		vec.push_back(num);
	}
	int arr[vec.size()];
	vector<pair<string,pair<int,int> > >res;
	bool ban=1;
	for(int i=0; i<100 and ban;i ++)
	{
		

		for(int j=0; j<100 and ban; j++)
		{
			for(int h=0; h<vec.size(); h++)
				arr[h]=vec[h];
			arr[1]=i;
			arr[2]=j;
			cout<<i<<" "<<j<<endl;
			int punt=0;
			while(arr[punt]!=99)
			{
				int a=arr[punt];
				int b=arr[punt+1];
				int c=arr[punt+2];
				int d=arr[punt+3];
				int poner;
				if(d>vec.size() )
				{
					res.push_back({"no",{i,j} });
					break;
				}
				if(a==1)
					poner=arr[b]+arr[c];
				else
				{
					if(a==2)
						poner=arr[b]*arr[c];
					else
					{
						res.push_back({"no",{i,j} });
						break;
					}
				}
				arr[d]=poner;
				punt+=4;
				cout<<" "<<punt<<" "<<a<<" "<<b<<" " <<c<<" "<<d<<endl;
				if(punt>vec.size() )
				{
					res.push_back({"no",{i,j} });
					break;
				}
			}
			if(arr[0]==19690720)
			{
				res.push_back({"yes",{i,j}});
				ban=0;
			}
		}
	}
	for(auto x: res)
		cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;

	cout<<(100*33)+76<<endl;

}