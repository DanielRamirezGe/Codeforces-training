#include <bits/stdc++.h>
using namespace std; 
int main()
{
	string cad;
	cin>>cad;
	string dos;
	vector<string> vec;
	getline(cin,cad);
	while(getline(cin,cad) and cad!="___________")
	{
		int sum=0;
		//cout<<cad<<endl;
		if(cad[9]=='o')
			sum++;
		if(cad[8]=='o')
			sum+=2;
		if(cad[7]=='o')
			sum+=4;
		if(cad[5]=='o')
			sum+=(8*1);
		if(cad[4]=='o')
			sum+=(8*2);
		if(cad[3]=='o')
			sum+=(8*4);
		if(cad[2]=='o')
			sum+=64;
		if(cad[1]=='o')
			sum+=256;
		//cout<<cad<<" "<<sum;
		if(sum==13)
			cout<<endl;
		else
		printf("%c",sum);
	}
	//256 128 64 32 16 8   8
//	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

//\:;<=>?@ [\]^_`\

}