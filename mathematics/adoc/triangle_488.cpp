#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num,a,b;
	cin>>num;
	for(int q=0; q<num; q++)
	{
		cin>>a>>b;
		for(int i=0; i<b; i++)
		{
			for(int j=1;j<=a;j++)
			{
				for(int h=1; h<=j; h++)
					cout<<j;
				cout<<endl;
			}
			for(int j=a-1; j>=1; j--)
			{
				for(int h=1; h<=j; h++)
					cout<<j;
				cout<<endl;
			}
			if(q!=num-1 or i!=b-1 )
			{
				//cout<<"entro"<<endl;
				cout<<endl;
			}
		}
	}
}