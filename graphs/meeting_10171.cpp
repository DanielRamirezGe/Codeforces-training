#include <bits/stdc++.h>
using namespace std;
#define maxi 30
#define inf 99999999
int main()
{
	int lines;
	int  young[maxi][maxi];
	int old[maxi][maxi];
	while(cin>>lines and lines!=0)
	{
		for(int i=0; i<maxi; i++)
			for(int j=0; j<maxi; j++)
			{
				if(i!=j)
				{
					young[i][j]=inf;
					old[i][j]=inf;
				}
				else
				{
					young[i][j]=0;
					old[i][j]=0;

				}
			}
		char type, direc,a,b;
		int dis;
		for(int i=0; i<lines; i++)
		{
			cin>>type>>direc>>a>>b>>dis;
			//cout<<type<<" "<<direc<<" "<<a<<" "<<b<<" "<<dis<<endl;
			if(type=='Y' and a!=b)
			{
				young[a-'A'][b-'A']=dis;
				if(direc=='B')
					young[b-'A'][a-'A']=dis;
				//cout<<young[a-'A'][b-'A']<<endl;

			}
			else
			{
				if(a!=b)
				{
					old[a-'A'][b-'A']=dis;
					if(direc=='B')
						old[b-'A'][a-'A']=dis;
					//cout<<old[a-'A'][b-'A']<<endl;
				}
			}
		}

		cin>>a>>b;
		//cout<<a<<" "<<b<<endl;
		// AdjMat is a 32-bit signed integer array
		for (int k = 0; k < maxi; k++)
			for (int i = 0; i < maxi; i++)
				for (int j = 0; j < maxi; j++)
					young[i][j] = min(young[i][j], young[i][k] + young[k][j]);

		for (int k = 0; k < maxi; k++)
			for (int i = 0; i < maxi; i++)
				for (int j = 0; j < maxi; j++)
					old[i][j] = min(old[i][j], old[i][k] + old[k][j]);

		int min=inf,city;
		vector<char> vec;
		for(int i=0; i<maxi; i++)
		{
			
			//cout<<young[a-'A'][i]<<" "<<old[b-'A'][i]<<" "<<min<<endl;
			if(young[a-'A'][i]+old[b-'A'][i] < min)
			{
				min=young[a-'A'][i]+old[b-'A'][i];
				vec.clear();
				vec.push_back('A'+i);
			}
			else
				if(young[a-'A'][i]+old[b-'A'][i]==min)
					vec.push_back('A'+i);
		}
		if(min==inf)
			cout<<"You will never meet."<<endl;
		else
			{			
				cout<<min<<" ";
				for(int j=0; j<vec.size(); j++)
				{
					if(j!=vec.size()-1)
						cout<<vec[j]<<" ";
					else
						cout<<vec[j]<<endl;
				}
			}


	}
}