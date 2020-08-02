#include <bits/stdc++.h>
using namespace std;
int main()
{
	char p;
	int altura,k;
	cin>>altura>>k;
	char l[altura],r[altura];
	for(int i=0; i<altura; i++)
	{
		cin>>l[i];
	}

	for(int i=0; i<altura; i++)
	{
		cin>>r[i];
	}
	
	
	priority_queue < pair< pair< int,int>,int > > q;
	q.push({{0,1},-1 });
	bool ban=0;
	bool dis_l[altura+k];
	bool dis_r[altura+k];
	memset(dis_l, 0,sizeof(dis_l) );
	memset(dis_r, 0,sizeof(dis_r) );
	while(!q.empty() and !ban)
	{
		auto a=q.top();
		int alt=a.first.first;
		int est=a.first.second;
		int wat=a.second;
		//cout<<alt<<" "<<est<<" "<<wat<<endl;
		q.pop();
		if(alt>=altura)
		{
			ban=1;
			break;
		}
		if(est==1)
		{
			dis_l[alt]=1;
			if( alt+1<altura)
			{
				if(l[alt+1]!='X'  and !dis_l[alt+1])
					q.push({{alt+1,1},wat+1 });
			}
			else
			{
				ban=1;
					break;
			}
			if(alt-1 > wat+1 and l[alt-1]!='X' and !dis_l[alt-1])
				q.push({ {alt-1, 1}, wat+1});
			
			if(alt+k<altura)
			{
				if(r[alt+k]!='X' and !dis_r[alt+k])
					q.push({{alt+k, 2},wat+1});
			}
			else
			{
				ban=1;
					break;
			}
			
		}
		else
		{
			dis_r[alt]=1;
			if( alt+1 < altura)
			{
				if(r[alt+1]!='X' and !dis_r[alt+1])
					q.push({{alt+1,2},wat+1});
			}
			else
			{
				ban=1;
				break;
			}
			if(alt-1>wat+1 and r[alt-1]!='X' and !dis_r[alt-1])
				q.push( {{alt-1, 2}, wat+1} );	

			if(alt+k < altura)
			{
				if(l[alt+k]!='X' and !dis_l[alt+k])
					q.push( {{alt+k, 1},wat+1 });
			}
			else
			{
				ban=1;
				break;
			}

	
		}
		
	}
	if(ban)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}