#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int con=0;
	if(max(a,b)<c)
	{
		int uno=max(a,b);
		int dos=c-max(a,b);
		for(int i=0; i<c*2; i++)
		{
			if(uno<=a and uno>=0 and dos>=0 and dos<=b)
				con++;
			uno--;
			dos++;
		}
	}
	else
	{
		int uno=c;
		int dos=0;
		for(int i=0; i<2*c; i++)
		{
			if(uno>=0 and dos<=min(a,b))
				con++;
			uno--;
			dos++;
		}
	}
	cout<<con<<endl;

}