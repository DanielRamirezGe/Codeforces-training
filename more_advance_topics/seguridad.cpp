#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;

	for(int i=0; i<a.size(); i++)
	{
		int res=0;
		if(a[i]>b[i])
		{
			res='z'-a[i];
			res+=b[i]-'a';
			printf("%c",'A'+res+1);
		}
		else
		{
			res=b[i]-a[i];
			printf("%c",'A'+res);
		}
	}
}