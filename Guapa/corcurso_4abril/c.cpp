#include <bits/stdc++.h>
#define maxn 100007

using namespace std;

vector<int> lista[ maxn ];
int s[ maxn ];
int n;

int bfs( int root )
{
    int v, front, len, max = 0;
    
    if( s[ root ] == -1 )
        s[ root ] = 0;
    else
        max = s[ root ];
    
    queue<int> q;
    q.push( root );
    
    while( !q.empty() )
    {
        front = q.front(); q.pop();
        
        len = lista[ front ].size(); 
        for( int i=0; i<len; ++i)
        {
            v = lista[ front ][ i ];
            
            if( s[ v ] != -1 && s[ v ] < s[ front ])
                return -1;
            
            if( s[ v ] == -1 )
                s[ v ] = s[ front ];
            else
                max += ( s[ v ] - s[ front ] );
            
            q.push( v );
        }
    }
    
    return max;
}

int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    
    int a;
    cin >> n;
    
    for( int i = 1; i < n; ++i)
    {
        cin >> a;
        lista[ a-1 ].push_back( i );
    }
    
    for( int i=0; i<n ; ++i )
        cin >> s[ i ];
    
    cout << bfs( 0 ) << endl;
    return 0;
}
