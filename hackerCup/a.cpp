	#include <bits/stdc++.h>
	using namespace std;
	#define mx 100
	vector <int> mat[mx];
	bool vis[mx];
	void f(int n){
		vis[n]=1;
		for(auto x : mat[n])
			if(!vis[x])
				f(x);
	}
	int main()
	{
		int cases;
		cin>>cases;
		for(int i=0; i<cases; i++)
		{
			for(int i=0; i<mx; i++)
				mat[i].clear();
			int n;
			cin>>n;
			string cad1,cad2;
			cin>>cad1>>cad2;
			for(int i=0; i<cad1.size(); i++){
				if( cad1[i] == 'Y' ){
					if(i!=0)
						if(cad2[i-1]=='Y')
							mat[i-1].push_back(i);

					if(i!=n-1)
						if(cad2[i+1]=='Y')
							mat[i+1].push_back(i);
				}
			}
			for(int i=0; i<cad2.size(); i++){

				if( cad2[i] == 'Y'){
					if(i!=0)
						if(cad1[i-1]=='Y')
							mat[i].push_back(i-1);

					if(i!=n-1)
						if(cad1[i+1]=='Y')
							mat[i].push_back(i+1);
				}
			}

			char ans[n][n];
			for(int i=0; i<n; i++)
			{
				memset(vis, 0, sizeof(vis));
				f(i);
				for(int j=0; j<n; j++)
				{
					if(vis[j])
						ans[i][j]='Y';
					else
						ans[i][j]='N';
				}
			}
			cout<<"Case #"<<i+1<<": "<<endl;
			for(int i=0; i<n; i++ )
			{
				for(int j=0; j<n; j++)
					cout<<ans[i][j];
				cout<<endl;	
			}

		}
	}