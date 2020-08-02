#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	string dos;
	int con=1;
	int res=0;
	for(int i=cad.size()-1 ; i>=0; i--)
		dos.push_back(cad[i]);
	bool ban=1;
	for(int i=0; i<dos.size(); i++)
	{
		
		if(i%2==1	 and ban)
			res++;
		if(i%2==0 and !ban)
			res++;
		if(dos[i]=='1' and ban)
		{
			ban=0;
			if(i%2==0 and i+1<dos.size())
				res++;
			
		}

	}
	cout<<res<<endl;

	
}