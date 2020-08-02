#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	priority_queue <pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > both, del, jen, any;
	for(int i=1; i<=n; i++){
		int t,a,b;
		cin>>t>>a>>b;
		if(a and b)
			both.push({t,i});
		if(a and !b)
			del.push({t,i});
		if(!a and b)
			jen.push({t,i});
		if( !a and !b)
			any.push({t,i});
	}
	int k1=k, k2=k;
	int con=0;
	vector<pair<int,int>> ans;
	bool ban = 0;
	while(k1 or k2 or m>0)
	{
		//cout<< k1<<" "<<k2<<" "<<m<<endl;
		if(k1 and k2){
			if(!both.empty() and !del.empty() and !jen.empty())
			{
				int one = both.top().first;
				int two = del.top().first + jen.top().first;
				if(one < two){
					ans.push_back(both.top());
					both.pop();
					m--;
				}
				else{
					ans.push_back(del.top());
					ans.push_back(jen.top());
					del.pop();
					jen.pop();
					m -= 2;
				}
				k1--;
				k2--;
			}
			else if (!del.empty() and !jen.empty()){
				ans.push_back(del.top());
				ans.push_back(jen.top());
				del.pop();
				jen.pop();
				k1--;
				k2--;
				m -= 2;

			}
			else if(!both.empty()){
				ans.push_back(both.top());
				both.pop();
				k1--;
				k2--;
				m--;

			}
			else{
				ban = 1;
				break;
			}


		}
		else if(k1){
			if(!both.empty() and !del.empty()){
				if(both.top().first < del.top().first)
				{
					ans.push_back(both.top());
					both.pop();	
				}
				else
				{
					ans.push_back(del.top());
					del.pop();
				}
				k1--;
				m--;
			}
			else if(!both.empty() ){
				ans.push_back(both.top());
				both.pop();	
				k1--;
				m--;
			}
			else if(!del.empty() ){
				ans.push_back(del.top());
				del.pop();	
				k1--;
				m--;
			}
			else{
				ban = 1;
				break;
			}

			
		}
		else if(k2)
		{
			if(!both.empty() and !jen.empty()){
				if(both.top().first < jen.top().first)
				{
					ans.push_back(both.top());
					both.pop();	
				}
				else
				{
					ans.push_back(jen.top());
					jen.pop();
				}
				k2--;
				m--;
			}
			else if(!both.empty() ){
				ans.push_back(both.top());
				both.pop();	
				k2--;
				m--;
			}
			else if(!jen.empty() ){
				ans.push_back(jen.top());
				jen.pop();	
				k2--;
				m--;
			}
			else{
				ban = 1;
				break;
			}

			
		}
		else{
			

			int mi = 99999999;
			if(!any.empty())
				mi = min( mi,any.top().first);
			if(!jen.empty())
				mi = min( mi,jen.top().first);
			if(!del.empty())
				mi = min( mi,del.top().first);
			if(!both.empty())
				mi = min( mi,both.top().first);

			if(!any.empty() and mi == any.top().first){
				ans.push_back(any.top());
				any.pop();
			}
			if(!jen.empty() and mi == jen.top().first){
				ans.push_back(jen.top());
				jen.pop();
			}
			if(!del.empty() and mi == del.top().first){
				ans.push_back(del.top());
				del.pop();
			}
			if(!both.empty() and mi == both.top().first){
				ans.push_back(both.top());
				both.pop();
			}
			m--;


		}
	}
	if(ban)
		cout<< -1<< endl;
	else
	{
		int tot = 0;
		for(int i=0; i<ans.size(); i++)
			tot += ans[i].first;
		cout<<tot<<endl;
		for(int i=0; i<ans.size(); i++)
		{
			if(i != ans.size()-1)
				cout<<ans[i].second<<" ";
			else
				cout<<ans[i].second<<endl;
		}
	}
}