#include <bits/stdc++.h>
using namespace std;
long long g(long long n)
{
	return (n*(n+1))/2;
}
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		string cad;
		cin>>cad;
		long long tot = 0;
		int ant = 0;
		int con=0;
		for(int i=1; i<=cad.size(); i++){
			if(cad[i-1]=='-')
			{
				if(con==0){
					tot +=  i-1;
					ant = i-1; 

					while( i <= cad.size()){
						
						if( cad[i-1] == '+'){
							//cout<<" antes "<<tot<<endl;
							tot += (g(i-1) - g(ant));
							//cout<<" despues: "<<tot<<"  "<<g(i-1)<<"  "<<g(ant)<<"  "<<i<<endl;
							con=1;
							if(i == cad.size() )
								tot += i;
							break;
						}
						if( i == cad.size() )
						{
							tot += (g(i) - g(ant)) + i; 
							break;
						}
						i++;
					}

				}
				else{
					con --;
					if( i == cad.size() )
						tot += i;
				}
			}
			else{
				con ++;
				if( i == cad.size() )
						tot += i;

			}
		}
		cout<<tot<<endl;

	}
}