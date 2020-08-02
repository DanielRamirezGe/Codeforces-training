#include <bits/stdc++.h>
using namespace std;
#define max_pos 1005
#define max_mod 1005
int respuesta[max_mod][max_pos];
int mat_mod[max_pos];
string original,copia;
int mod;
vector<int> vec;
vector<int> numbers;
int f( int modulo, int pos)
{
	if(pos==vec.size())
	{
		if(modulo==0)
		{
			int con=0;
			for(int i=0; i<original.size(); i++)
			{
				if(original[i]=='?')
				{
					cout<<numbers[con];
					con++;
				}
				else
					cout<<original[i];
			}
			return -1;
		}
		else
			return 1;
	}
	else
	{
		if(respuesta[modulo%mod][pos])
			return 1;
		for(int i=0; i<10; i++)
		{
			if( !respuesta[((modulo%mod)+(i*mat_mod[vec[pos]]))%mod][pos+1] )
			{
				numbers.push_back(i);
				respuesta[((modulo%mod)+(i*mat_mod[vec[pos]]))%mod][pos+1]= f( ((modulo%mod)+(i*mat_mod[vec[pos]]))%mod, pos+1);
				if( respuesta[((modulo%mod)+(i*mat_mod[vec[pos]]))%mod][pos+1] == -1)
					return -1;
				numbers.pop_back();
			}
		}
	}

}
int main()
{
	memset(respuesta,0,sizeof(respuesta));
	cin>>original>>mod;
	mat_mod[0]=1%mod;
	for(int i=1; i<max_pos; i++)
		mat_mod[i]=((mat_mod[i-1])*10)%mod;
	
	
	copia=original;
	int res=0;
	if(copia[0]=='?')
	{
		copia[0]='1';
		vec.push_back(copia.size()-1);
	}
	for(int i=1; i<copia.size(); i++)
	{
		if(copia[i]=='?')
		{
			copia[i]='0';
			vec.push_back(original.size()-i-1);
		}
	}

	for(int i=0; i<copia.size(); i++)
	{
		res*=10;
		res+=copia[i]-'0';
		res=res%mod;
	}
	if(original[0]=='?')
	{
		numbers.push_back(1);
		if(f(res,1)!=-1)
		{
			numbers.pop_back();
			bool b=1;
			for(int i=2; i<10; i++)
			{
				numbers.push_back(i);
				if(f((res+((i-1)*mat_mod[vec[0]]))%mod,1)==-1)
				{
					b=0;
					break;
				}
				numbers.pop_back();
			}
			if(b)
				cout<<'*';
		}
	}
	else
	{	
		bool ban=1;
		for(int i=0; i<10; i++)
		{
			numbers.push_back(i);
			if(f((res+(i*mat_mod[vec[0]]))%mod,1)==-1)
			{
				ban=0;
				break;
			}
			numbers.pop_back();
		}
		if(ban)
			cout<<'*';
	}
	cout<<endl;

}