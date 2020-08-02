#include <iostream>
#include <cstring>
#define maximo 100005
#define let 27

using namespace std;

char uno[maximo];
char dos[maximo];
int acc[let][maximo];
bool mapa[let][let];

int main()
{
    int cases;
    scanf("%d",&cases);

    while( cases-- )
    {
        char aux;
        int a,b,k;
        memset(mapa, 0, sizeof(mapa));
        
        scanf("%d %d %d",&a,&b,&k);
        
        scanf("%c",&aux);
        scanf("%s",&uno);
        
        scanf("%c",&aux);
        scanf("%s",&dos);
        
        //cout<<a<<" "<<b<<" "<<k<<" "<<uno<<" - "<<dos<<endl;
        //cout<<uno<<" "<<dos<<endl;
        int con = 0;
        for(int i=k-1; i<a; ++i)
        {
            //cout<<uno[con]<<" "<<uno[con]-'a'<<" "<<uno[i]<<" "<<uno[i]-'a'<<endl;
            mapa[ uno[con]-'a' ][ uno[i]-'a' ] = true;
            ++con;
        }
        
        long long ans = 0;
        memset(acc, 0, sizeof(acc));
        for(int p=0; p<b; p++)
        {
            acc[dos[p]-'a'][p]=1;
        }
        for(int p=0; p<let; p++)
            for(int q=b-1; q>=0; q-- )
                acc[p][q]+=acc[p][q+1];

        for(int i=0; i<let; ++i)
        {
            for(int j=0; j<let; ++j)
            {
                if(mapa[i][j])
                {
                    for( int h=0; h<b; ++h )
                        if( dos[h]-'a' == i )
                        {
                            //cout<<h<<" "<<(char)('a'+i)<<"   "<<acc[h]<<endl;
                            ans += acc[j][h];
                        }
                }
            }
        }
		printf("%lld\n",ans );
        
	}
}