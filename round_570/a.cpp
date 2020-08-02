#include <bits/stdc++.h>
using namespace std;
int main()
{
	int suma=0,n,aux;
	cin>>n;
	aux=n;
    do
    {
        suma=0;
        aux=n;
        while(aux)
        {
            suma+=aux%10;
            aux/=10;
        }
        n++;
        
    }while(suma%4!=0);
    n--;
	cout<<n<<endl;

}
