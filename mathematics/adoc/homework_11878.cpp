#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	int con=0;
	while(getline(cin, cad))
	{
		int a=0, b=0, c=0;
		bool ban=1;
		bool sig=1;
		for(int i=0; i<cad.size() and ban; i++)
		{
			//cout<<cad[i]<<" "<<i<<endl;
			if(cad[i]=='+' or cad[i]=='-')
			{
				if(cad[i]=='-')
					sig=0;
				i++;
				for(; i<cad.size() and ban; i++)
				{
					if(cad[i]=='=')
					{
						i++;
						for(; i<cad.size(); i++)
						{
							c*=10;
							c+=cad[i]-'0';
						}
						ban=0;
						break;
					}
					b*=10;
					b+=cad[i]-'0';
					
				}
			}
			else
			{
				a*=10;
				//cout<<cad[i]<<endl;
				a+=cad[i]-'0';
				//cout<<a<<endl;
			}
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if(sig==1)
		{
			if(a+b==c)
				con++;
		}
		else
			if(a-b==c)
				con++;

	}
	cout<<con<<endl;
}