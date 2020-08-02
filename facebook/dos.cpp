#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % mod;
        }
        base = (base * base) % mod;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

int main()
{
	int cases;
	cin>>cases;
	string cad;
	for(int i=0; i<cases; i++)
	{
		int n,esp;
		cin>>n>>esp;
		long long tot=0;
		
		cin>>cad;
		for(int j=1; j<=cad.size(); j++ )
		{
			
			int b=0,a=0;
			deque <pair<char,int>> q;
			for(int k=0; k<j; k++)
			{
				if(cad[k]=='B')
					b++;
				else
					a++;
				q.push_back({cad[k],k});
			}
			if(b>a+esp)
			{
				int ind=0;
				while(b>a+esp)
				{
					if(q[ind].first=='B')
					{
						b--;
						tot=(tot+fast_power(2,(q[ind].second)+1) )%mod;
						q[ind].first='A';
						cad[q[ind].second]='A';
						a++;
					}
					ind++;
				}
			}
			for(int k=j; k<cad.size(); k++)
			{
				if(q.front().first=='A')
					a--;
				else
					b--;
				q.pop_front();
				q.push_back({cad[k],k});
				if(cad[k]=='B')
					b++;
				else
					a++;
				
				if(b>a+esp)
				{
					cout<<"    "<<k<<endl;
					int ind=0;
					while(b>a+esp)
					{

						if(q[ind].first=='B')
						{
							b--;
							a++;
							tot=(tot+fast_power(2,(q[ind].second)+1) )%mod;
							q[ind].first='A';
							cad[q[ind].second]='A';
						}
						ind++;
					}
				}
			}

		}
		cout<<"Case #"<<i+1<<": "<<tot<<endl;
	}
}