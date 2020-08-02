#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld eps=1e-9, inf = numeric_limits<ld>::max();
bool geq(ld a, ld b){return a-b >= -eps;}
bool leq(ld a, ld b){return b-a >= -eps;}
bool ge(ld a, ld b){return a-b > eps;}
bool le(ld a, ld b){return b-a > eps;}
bool eq(ld a, ld b){return abs(a-b) <= eps;}
bool neq (ld a, ld b){return abs(a-b)> eps ;}
 
 
 
struct point{ 
	ld x,y;
	point (): x(0), y(0){}
	point (ld x,ld y): x(x), y(y){}
	point operator +(const point & p)const{return point(x+p.x, y+p.y);}
	point operator -(const point & p)const{return point(x-p.x, y-p.y);}
	point operator *(const ld & k)const{return point(x*k, y*k);}
	point operator /(const ld & k)const{return point(x/k, y/k);}
	bool operator <(const point &p)const{
		if(eq(x,p.x))return le(y,p.y);
		return le(x,p.x);
	}
	point rotate(const ld& angle)const{
		return point(x-cos(angle)- y*sin(angle), x*sin(angle)+ y*cos(angle));
	}
 
	ld cross (const point &p )const{return x*p.y - y*p.x;}
 	ld dot(const point &p) const{return x*p.x + y*p.y;}
	long double length() const{return sqrt(x*x +y*y);}
	
 
};
int sgn (ld x)
{
	if(ge(x,0))return 1;
	if(le(x,0))return -1;
	return 0;
}
ld area( vector <point> &p)
{
	int n= p.size();
	ld ans=0;
	for(int i=0; i<n; i++)
	{
		ans += p[i].cross(p[(i+1)%n]);
	}
	return abs(ans/2);
}
 
vector<point> process(vector <point> &p)
{ 
	int n=p.size();
	rotate(p.begin(), min_element(p.begin(),p.end()), p.end());
	vector <point> seg(n-1);
	for(int i=0; i<n-1; i++)
		seg[i]=p[i+1]-p[0];
	return seg;
}
 
bool pointIn(const vector<point> &seg, const point &p)
{
	int n=seg.size();
	if(neq(seg[0].cross(p),0) && sgn(seg[0].cross(p))!=sgn(seg[0].cross(seg[n-1])) )
		return false;
	if(neq(seg[n-1].cross(p),0) && sgn(seg[n-1].cross(p)) != sgn(seg[n-1].cross(seg[0])))
		return false;
	if(eq(seg[0].cross(p),0))
		return geq(seg[0].length(), p.length());
	int l=0, r=n-1;
	while(r-1 > 1)
	{
		int m=l+((r-1)>>1);
		if(geq(seg[m].cross(p),0)) l=m;
		else
			r=m;
 
	}
	return eq(abs(seg[l].cross(seg[l+1])),abs((p-seg[l]).cross(p-seg[l+1]))+abs(p.cross(seg[l])) +abs(p.cross(seg[l+1])));
}
bool fun(point x, point y)
{
	if(x.x<y.x || x.x>y.x)
		return x.x<y.x;
	return x.y<y.y;
}
bool pointInLine(const point & a, const point & v, const point & p)
{
	return eq((p-a).cross(v),0);
}
bool pointInSeg(const point & a, const point & b, const point & p)
{
	return pointInLine(a,b-a,p) && leq((a-p).dot(b-p),0);
}

bool intersectSeg(const point & a, const point &b, const point & c, const point & d)
{
	point v1=b-a, v2=d-c;
	int t= sgn(v1.cross(c-a)), u=sgn(v1.cross(d-a));
	if(t==u)
	{
		if(t==0)
		{
			if(pointInSeg(a,b,c) || pointInSeg(a,b,d) || pointInSeg( c,d,a) || pointInSeg(c,d,b))
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return sgn(v2.cross(a-c) != sgn(v2.cross(b-c)));
}


int main(){
	vector <point> uno,dos;
	point aux;
	for(int i=0; i<4; i++)
	{
		cin>>aux.x;
		cin>>aux.y;
		// aux.x+=110;
		// aux.y+=110;
		uno.push_back(aux);
	}
	for(int i=0; i<4; i++)
	{
		cin>>aux.x;
		cin>>aux.y;

		// aux.x+=110;
		// aux.y+=110;
		dos.push_back(aux);
	}
	sort(uno.begin(), uno.end(), fun);
 
	sort(dos.begin(), dos.end(), fun);
	bool ans=false;
	
	for(int i=0; i<4; i++)
	{
		vector <point> res=process(uno);
		bool r=pointIn(res, dos[i]-uno[0]);
		if(r)
			ans=true;
		
	}
	for(int i=0; i<4; i++)
	{
		vector <point> res=process(dos);
		bool r=pointIn(res, uno[i]-dos[0]);
		
		if(r)
		{
			
			ans=true;
		}
		
	}<
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int k=0; k<4; k++)
				for(int l=0; l<4; l++)
				{	
					//cout<<uno[i].x<<" "<<uno[i].y<<" "<<uno[j].x<<" "<<uno[j].y<<" "<<dos[k].x<<" "<<dos[k].y<<" "<<dos[l].x<<" "<<dos[l].y<<endl;
					bool r=intersectSeg(uno[i],uno[j], dos[k], dos[l]);
					if(r)	
					{
						cout<<uno[i].x<<" "<<uno[i].y<<" "<<uno[j].x<<" "<<uno[j].y<<" "<<dos[k].x<<" "<<dos[k].y<<" "<<dos[j].x<<" "<<dos[j].y<<endl;
						ans=true;

					}
		
				}
		
		
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}