
#include<bits/stdc++.h> 
using namespace std; 
struct circle{
    int x,y,R;
};
struct point{
    int x,y;
};
int overlap(circle C, point p1, point p2)
{
    int Xnew = max(p1.x, min(C.x, p2.x));
    int Ynew = max(p1.y, min(C.y, p2.y));
    int diff_x = Xnew - C.x;
    int diff_y = Ynew - C.y;
    long long val = diff_x * diff_x + diff_y * diff_y;
    if (val > C.R * C.R)
        return 0;
    if (val == C.R * C.R)
        return 1;
    return 2;
}

int main() 
{ 
    int s;  
    circle C;
    point a,b;
    cin >> C.x >> C.y >> C.R >> a.x >> a.y >> s;
    b.x = a.x + s;
    b.y = a.y + s;
    cout <<overlap(C,a,b)<<endl; 
} 
