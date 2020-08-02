#include <bits/stdc++.h>
using namespace std;
typedef int t;
#define cp const point  
#define ep 1e-7
struct point {
    t x,y;
    point()
    {
        x=y=0.0;
    }
    point(t a, t b): x(a),y(b){}
    point operator + (cp &nuevo) const
    {
        return point(x+nuevo.x, y+nuevo.y);
    }
    point operator - (cp &nuevo)const
    {
        return point(x-nuevo.x, y-nuevo.y);
    }
    t operator * (cp &nuevo) const
    {
        return (x*nuevo.x)-(y*nuevo.y);
    }
    t operator ^ (cp &nuevo) const
    {
        return (x*nuevo.y)-(y*nuevo.x);
    }
    bool operator < (cp &nuevo) const
    {
        if(abs(x-nuevo.x)>ep)
            return (x<nuevo.x);
        return (y<nuevo.y);
    }
};
int cross (point a, point b, point c)
{
     t det=(b-a)^(c-a);
     if(abs(det)<=ep)
        return 0;
     if(det<ep)
        return -1;
     return 1;
}
bool on_seg(point p1, point p2, point q1)
{

    int x1=min(p1.x,p2.x);
    int x2=max(p1.x, p2.x);
    int y1=min(p1.y, p2.y);
    int y2=max(p1.y, p2.y);
    int x=q1.x;
    int y=q1.y;
   // cout<<p1.x<<" "<<p2.x<<" "<<p1.y<<" "<<p2.y<<endl;
    //cout<<x1<<" "<<x<<" "<<x2<<" "<<y1<<" "<<y<<" "<<y2<<endl;
    if( (x1<=x and x<=x2) and (y1<=y and y<=y2)  )
        return true;
    return false;
}
bool inter(point p1, point p2, point q1, point q2)
{
    int a,b,c,d;
    a=cross(p1,p2,q1);
    b=cross(p1,p2,q2);
    c=cross(q1,q2,p1);
    d=cross(q1,q2,p2);

    if(a!=b and c!=d)
        return true;

    if(a==0 and on_seg(p1,p2,q1))
        return true;
    if(b==0 and on_seg(p1,p2,q2))
        return true;
    if(c==0 and on_seg(q1,q2,p1))
        return true;
    if(d==0 and on_seg(q1,q2,p2))
        return true;
    return false;
}
bool i_p(point l, point r, point po)
{
    int y1=min(r.y, l.y);
    int y2=max(l.y, r.y);
    int x1=min(l.x, r.x);
    int x2=max(r.x,l.x);
    int y=po.y;
    int x=po.x;
    if(y1<=y and y<=y2 and x1<=x and x<=x2)
        return true;
    return false;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++)
    {       
        bool ban=0;
        int x,y;
        cin>>x>>y;
        point p1(x,y);
        cin>>x>>y;
        point p2(x,y);
        cin>>x>>y;
        point let(x,y);
        cin>>x>>y;
        point rigt(x,y); 
       // if(i==5)
   		//	cout<<"inicio"<<endl;       
    
   		if(i_p(let,rigt, p1))
   				ban=1; 
   		
   		if(i_p(let,rigt, p2))
   			ban=1;

       point uno(let.x,rigt.y);
       point dos(rigt.x, let.y);
        
        if(inter(p1,p2, let, uno))
            ban=1;
        if(inter(p1,p2, let, dos))
             ban=1;            
        if(inter(p1,p2, rigt, uno))
            ban=1;
        if(inter(p1,p2, rigt, dos))
            ban=1;
        // if(i==5)
   		//	cout<<"fin"<<endl; 
        if(ban)
            cout<<"T\n";
        else
            cout<<"F\n";}
}