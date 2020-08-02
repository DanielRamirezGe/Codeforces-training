#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	vector <int> vec;
	while(cin>>num and num!=0)
	{
		vec.clear();
		vec.push_back(num);
		while(cin>>num and num!=0)
		{
			//cout<<num<<endl;
			vec.push_back(num);
		}

		vector<int> res;
		int uno,dos,p;
		for(int i=1; i<vec.size(); i++)
		{	
			uno=vec[i-1];
			dos=vec[i];
			p=abs(uno-dos);
			//cout<<"  "<<p<<endl;
			res.push_back(p);
		}
		//cout<<"klkjlkj"<<endl;
		int imp;
		if(res.size()>1)
		{
			imp= __gcd(res[0],res[1]);
			for(int i=2; i<res.size(); i++)
				imp=__gcd(imp,res[i] );
			
		}
		else
		{
			imp=res[0];
		}
		cout<<imp<<endl;
	}
}