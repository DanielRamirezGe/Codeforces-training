#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i, x, num ,pos;
	vector<int>cn;
	vector<int>cp;
	vector<int>niu;
	while(cin>>n and n!=0)
	{
		int fla=1;
		cn.clear();
		cp.clear();
		niu.clear();
		for(int i=0; i<n; i++)
		{
			niu.push_back(0);
			cin>>num>>pos;
			cn.push_back(num);
			cp.push_back(pos);
		}	
		for(i=0;i<n;i++)
		{
			if(i+cp[i]<n && i+cp[i]>=0 and niu[i+cp[i]]==0)
				niu[i+cp[i]]=cn[i];
			else
				fla=0;

		}
		if(fla!=0)
		{
			for(i=0;i<n;i++)
			{
				cout<<niu[i];
				if(i!=n-1)
					cout<<" ";
			}
				
			cout<<endl;
		}
		else
			cout<<-1<<endl;
	}
	
}