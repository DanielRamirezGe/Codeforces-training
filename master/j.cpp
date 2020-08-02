#include <bits/stdc++.h>
using namespace std;
int x_ = 6;
int y_ = 5;
char mat[7][7],copia[7][7];
bool gana_dos(int i, int j)
{
	if(j+3<=x_)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i][j+h]=='Y')
				res=false;
		if(res)
			return true;
		if(i+3<=y_)
		{
			res=true;
			for(int h=1; h<=3; h++)
			if(mat[i+h][j+h]=='Y')
				res=false;
			if(res)
			return true;
		}
		if(i-3>=0)
		{
			res=true;
			for(int h=1; h<=3; h++)
				if(mat[i-h][j+h]=='Y')
					res=false;
			if(res)
				return true;
		}

	}
	if(j-3>=0)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i][j-h]=='Y')
				res=false;
		if(res)
			return true;
		if(i+3<=y_)
		{
			res=true;
			for(int h=1; h<=3; h++)
				if(mat[i+h][j-h]=='Y')
					res=false;
			if(res)
				return true;
		}

		if(i-3>=0)
		{
			res=true;
			for(int h=1; h<=3; h++)
				if(mat[i-h][j-h]=='Y')
					res=false;
			if(res)
				return true;
		}

	}
	if(i+3<=y_)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i+h][j]=='Y')
				res=false;
		if(res)
			return true;
	}
	if(i-3>=0)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i-h][j]=='Y')
				res=false;
		if(res)
			return true;
	}
	return false;
}
bool gana_uno(int i, int j)
{
	if(j+3<=x_)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i][j+h]=='R')
				res=false;
		if(res)
			return true;
		if(i+3<=y_)
		{
			res=true;
			for(int h=1; h<=3; h++)
			if(mat[i+h][j+h]=='R')
				res=false;
			if(res)
			return true;
		}
		if(i-3>=0)
		{
			res=true;
			for(int h=1; h<=3; h++)
				if(mat[i-h][j+h]=='R')
					res=false;
			if(res)
				return true;
		}

	}
	if(j-3>=0)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i][j-h]=='R')
				res=false;
		if(res)
			return true;
		if(i+3<=y_)
		{
			res=true;
			for(int h=1; h<=3; h++)
				if(mat[i+h][j-h]=='R')
					res=false;
			if(res)
				return true;
		}

		if(i-3>=0)
		{
			res=true;
			for(int h=1; h<=3; h++)
				if(mat[i-h][j-h]=='R')
					res=false;
			if(res)
				return true;
		}

	}
	if(i+3<=y_)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i+h][j]=='R')
				res=false;
		if(res)
			return true;
	}
	if(i-3>=0)
	{
		bool res=true;
		for(int h=1; h<=3; h++)
			if(mat[i-h][j]=='R')
				res=false;
		if(res)
			return true;
	}
	return false;
}
void dfs(int i,int j)
{
	copia[i][j]='x';
	if(j+1<=x_)
		if(copia[i][j+1]!='.' and copia[i][j+1]!='x')
			dfs(i, j+1);

	if(j+1<=x_ and i+1<= y_)
		if(copia[i+1][j+1]!='.' and copia[i+1][j+1]!='x')
			dfs(i+1, j+1);
	if(i+1<=y_)
		if(copia[i+1][j]!='.' and copia[i+1][j]!='x')
			dfs(i+1, j);
	if(j-1>=0)
		if(copia[i-1][j]!='.' and copia[i-1][j]!='x')
			dfs(i-1, j);
	if(j-1>=0)
		if(copia[i][j-1]!='.' and copia[i][j-1]!='x')
			dfs(i, j-1);
	if(j+1<=x_ and i-1>=0)
		if(copia[i-1][j+1]!='.' and copia[i-1][j+1]!='x')
			dfs(i-1, j+1);
	if(j-1>=0 and i+1<=y_)
		if(copia[i+1][j+1]!='.' and copia[i+1][j-1]!='x')
			dfs(i+1, j-1);
	if(j-1>=0 and i-1>=0)
		if(copia[i-1][j-1]!='.' and copia[i-1][j-1]!='x')
			dfs(i-1, j-1);
}
bool check()
{
	bool res=true;
	for(int i=0; i<6; i++)
		for(int j=0; j<7; j++)
			if(copia[i][j]!='.' and copia[i][j]!='x')
				res=false;
	return res;
}
bool dos(int i, int j)
{
	bool res=true;
	char bus=mat[i][j];
	int con=0;
	for(int h=0; j+h<=x_; h++ ){
		if(bus!=mat[i][j+h])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;

	for(int h=0; j-h>= 0; h++ ){
		if(bus!=mat[i][j-h])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;
	for(int h=0; i+h<=x_; h++ ){
		if(bus!=mat[i+h][j])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;
	for(int h=0; i - h>= 0; h++ ){
		if(bus!=mat[i-h][j])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;
	for(int h=0; j+h<=x_ and i+h<=y_; h++ ){
		if(bus!=mat[i+h][j+h])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;
	for(int h=0; j-h>=0 and i+h<=y_; h++ ){
		if(bus!=mat[i+h][j-h])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;
	for(int h=0; j+h<=x_ and i-h>=0; h++ ){
		if(bus!=mat[i-h][j+h])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	con=0;
	for(int h=0; j-h>=0 and i-h>=0; h++ ){
		if(bus!=mat[i-h][j-h])
			break;
		else
			con++;
	}
	if(con>=5)
		return false;
	return true;


}
int main()
{
	int cases;
	cin>>cases; 
	
	for(int m=0; m<cases; m++)
	{
		for(int i=0; i<6; i++)
			for(int j=0; j<7; j++)
			{
				cin>>mat[i][j];
				copia[i][j]=mat[i][j];
			}

		pair <int,int> imp;
		imp.first=0;
		imp.second=0;
		int con_uno=0;
		int con_dos=0; 
		bool err=0;
		for(int i=0; i<6; i++)
			for(int j=0; j<7; j++)
			{
				if(mat[i][j]!='.')
				{
					if(!dos(i,j))
						err= true;
				
				}
				if(mat[i][j]=='Y')
				{
					con_uno++;
					bool res=gana_uno(i,j);
					if(res)
					{
						imp.first++;
						imp.second=1;
					}

				}
			}

		for(int i=0; i<6; i++)
			for(int j=0; j<7; j++)	
				if(mat[i][j]=='R')
				{
					con_dos++;
					bool res=gana_dos(i,j);
					if(res)
					{
						imp.first++;
						imp.second=2;
					}

				}
		dfs(5,0);
		dfs(5,1);
		dfs(5,2);
		dfs(5,3);
		dfs(5,4);
		dfs(5,5);
		dfs(5,6);
		
		//cout<<"paso dos"<<endl;
		if(!check() or err)
		{
			cout<<"check"<<endl;
			cout<<-1<<endl;
			
		}
		else if(con_dos>con_uno)
		{
			cout<<-1<<endl;
			
		}
		else if(con_uno>con_dos+1)
		{
			cout<<-1<<endl;
		}
		else if(imp.first>1)
		{
			cout<<-1<<endl;
			
		}
		else if(imp.first==0)
		{
			bool si=false;
			for(int i=0; i<6; i++)
				for(int j=0; j<7; j++)
					if(mat[i][j]=='.')
						si=true;
			if(si)
			{
				if(con_uno<con_dos)
					cout<<1<<" "<<2<<endl;
				else
					cout<<1<<" "<<1<<endl;
			}
			else
				cout<<0<<" "<<0<<endl;
		

		}
		else
		{
			cout<<0<<" "<<imp.second<<endl;
			return 0;
		}




	}
}