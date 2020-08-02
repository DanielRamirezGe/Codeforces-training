#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > change(vector < vector<int> > &mat)
{
	int aux;	
	int n=mat.size();
	for(int i=0; i<n/2; i++)
	{
		for(int j=i; j<n-(2*i); j++)
		{
			if(i==0 and j==n-1)
				break;
			cout<<i<<" "<<j<<endl;
			aux=mat[j][n-i-1];
			mat[j][n-i-1]=mat[i][j];
			mat[i][j]=mat[n-j-1][i];
			mat[n-j-1][i]=mat[n-i-1][n-j-1];
			mat[n-i-1][n-j-1]=aux;
			
		}
	}
	return mat;
}
int main()
{
	vector <vector<int>> mat;
	vector<int> aux;
	int n, num;
	cin>>n;
	for(int i=0; i<n; i++)
	{

		aux.clear();
		for(int j=0; j<n; j++)
		{
			//cout<<i<<" "<<j<<endl;
			cin>>num;
			aux.push_back(num);
		}
		mat.push_back(aux);
	}
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0;j<mat[i].size(); j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	mat=change(mat);
	cout<<endl<<endl;
	for(int i=0; i<mat.size(); i++)
	{
		for(int j=0;j<mat[i].size(); j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}