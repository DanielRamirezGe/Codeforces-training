#include <bits/stdc++.h>
using namespace std;
int n;
string inst, cad;
vector<string> mat;
void r()
{
	vector<string> nuevo;
	string dos;
	for(int i=0; i<n; i++)
	{
		dos.clear();
		for(int j=n-1; j>=0 ; j--)
		{
			if(mat[j][i]=='<')
				dos.push_back('^');
			if(mat[j][i]=='>')
				dos.push_back('v');
			if(mat[j][i]=='v')
				dos.push_back('<');
			if(mat[j][i]=='^')
				dos.push_back('>');
			if(mat[j][i]=='.')
				dos.push_back('.');

		}
		//cout<<dos<<endl;
		nuevo.push_back(dos);
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			mat[i][j]=nuevo[i][j];
}
void l()
{
	vector<string> nuevo;
	string dos;
	for(int i=n-1; i>=0; i--)
	{
		dos.clear();
		for(int j=0; j<n ; j++)
		{
			if(mat[j][i]=='<')
				dos.push_back('v');
			if(mat[j][i]=='>')
				dos.push_back('^');
			if(mat[j][i]=='v')
				dos.push_back('>');
			if(mat[j][i]=='^')
				dos.push_back('<');
			if(mat[j][i]=='.')
				dos.push_back('.');

		}
		nuevo.push_back(dos);
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			mat[i][j]=nuevo[i][j];
}
int main()
{
	cin>>n;
	cin>>inst;
	for(int i=0; i<n; i++)
	{
		cin>>cad;
		mat.push_back(cad);
	}
	vector<string> resp[4],aux;
	for(int i=0; i<4; i++)
	{
		
			//for(int i=0; i<n; i++)
			//	cout<<mat[i]<<endl;
			//cout<<endl;
			for(int j=0; j<n; j++)
				resp[i].push_back(mat[j]);
				l();


	}
	int con=0;
	for(int i=0; i<inst.size(); i++)
	{
		if(inst[i]=='L')
			con++;
		else
			con--;
		con=(con+4)%4;
	}
	for(int i=0; i<n; i++)
		cout<<resp[con][i]<<endl;
}