#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
int main()
{
	int lend;
	cin>>lend;
	string cad;
	string com1,com2;
	getline(cin,cad);
	getline(cin,cad);
	com1=cad;
	sort(com1.begin(), com1.end());
	for(int i=0; i<lend; i++)
		if(cad[i]=='A')
			com2.push_back(cad[i]);

	for(int i=0; i<lend; i++)
		if(cad[i]=='C')
			com2.push_back(cad[i]);
	for(int i=0; i<lend; i++)
		if(cad[i]=='B')
			com2.push_back(cad[i]);
	int min=inf, a,b,c, ind_a_1,ind_a_2, ind_b_1, ind_b_2, ind_c_1, ind_c_2;
	bool ban_a,ban_b,ban_c;
	ind_a_1=ind_a_2=ind_b_1=ind_b_2=ind_c_1=ind_c_2=-1;
	a=b=c=0;
	ban_a=ban_b=ban_c=1;

	for(int i=0; i<lend; i++ )
	{
		if(com1[i]=='A' and ban_a)
		{
			ban_a=0;
			ind_a_1=i;
		}
		if(com1[i]=='B' and ban_b)
		{
			ban_b=0;
			ind_b_1=i;
		}
		if(com1[i]=='C' and ban_c)
		{
			ban_c=0;
			ind_c_1=i;
		}
		if(com1[i]=='A' )
			ind_a_2=i;
		
		if(com1[i]=='B' )
			ind_b_2=i;
		
		if(com1[i]=='C' )
			ind_c_2=i;

		if(com1[i]=='A' and cad[i]!='A')
			a++;
		if(com1[i]=='B' and cad[i]!='B')
			b++;
		if(com1[i]=='C' and cad[i]!='C')
			c++;
	}
	min=a+b+c;
	for(int i=0; i<lend; i++)
	{
		if(ind_a_1!=-1)
		{
			if(cad[ind_a_1]!='A')
				a--;
			ind_a_1++;
			ind_a_1%=lend;
			ind_a_2++;
			ind_a_2%=lend;
			if(cad[ind_a_2]!='A')
				a++;
		}
		if(ind_b_1!=-1)
		{		
			if(cad[ind_b_1]!='B')
				b--;
			ind_b_1++;
			ind_b_1%=lend;
			ind_b_2++;
			ind_b_2%=lend;
			if(cad[ind_b_2]!='B')
				b++;
		}
		
		if(ind_c_1!=-1)
		{	
			if(cad[ind_c_1]!='C')
				c--;
			ind_c_1++;
			ind_c_1%=lend;
			ind_c_2++;
			ind_c_2%=lend;
			if(cad[ind_c_2]!='C')
				c++;
		}
		if(a+b+c < min)
			min=a+b+c;
	}
	//cout<<min<<endl;
	ind_a_1=ind_a_2=ind_b_1=ind_b_2=ind_c_1=ind_c_2=-1;
	a=b=c=0;
	ban_a=ban_b=ban_c=1;

	for(int i=0; i<lend; i++ )
	{
		if(com2[i]=='A' and ban_a)
		{
			ban_a=0;
			ind_a_1=i;
		}
		if(com2[i]=='B' and ban_b)
		{
			ban_b=0;
			ind_b_1=i;
		}
		if(com2[i]=='C' and ban_c)
		{
			ban_c=0;
			ind_c_1=i;
		}
		if(com2[i]=='A' )
			ind_a_2=i;
		
		if(com2[i]=='B' )
			ind_b_2=i;
		
		if(com2[i]=='C' )
			ind_c_2=i;

		if(com2[i]=='A' and cad[i]!='A')
			a++;
		if(com2[i]=='B' and cad[i]!='B')
			b++;
		if(com2[i]=='C' and cad[i]!='C')
			c++;
	}
	if(a+b+c<min)
		min=a+b+c;
	for(int i=0; i<lend; i++)
	{	
		if(ind_a_1!=-1)	
		{
			if(cad[ind_a_1]!='A')
				a--;
			ind_a_1++;
			ind_a_1%=lend;
			ind_a_2++;
			ind_a_2%=lend;
			if(cad[ind_a_2]!='A')
				a++;
		
		}
		if(ind_b_1!=-1)
		{	
			if(cad[ind_b_1]!='B')
				b--;
			ind_b_1++;
			ind_b_1%=lend;
			ind_b_2++;
			ind_b_2%=lend;
			if(cad[ind_b_2]!='B')
				b++;
		}
		if(ind_c_1!=-1)
		{	
			if(cad[ind_c_1]!='C')
				c--;
			ind_c_1++;
			ind_c_1%=lend;
			ind_c_2++;
			ind_c_2%=lend;
			if(cad[ind_c_2]!='C')
				c++;
		}
		if(a+b+c < min)
			min=a+b+c;
		//cout<<a+b+c<<endl;
	}

	cout<<min<<endl;

}