#include <iostream>
#include <stdlib.h>
#include <vector> 
using namespace std;
struct node
{
	int data;
	node *left=NULL;
	node *right=NULL;
	bool use=false;

};
void put(node *current, int data)
{
	if(current->use==false)
	{
		current->data=data;
		current->use=true;
		return;
	}
	if(data < current->data)
	{
		if(current->left==NULL)
		{
			node *child=new(node);
			current->left=child;
		}
		put(current->left, data);
	}
	else
	{
		if(current->right==NULL)
		{
			node *child=new(node);
			current->right=child;
		}
		put(current->right, data);
	}

}
void in_orden(node *n, vector<int> &vec)
{
	if(n==NULL)
		return;
	in_orden(n->right,vec);
	vec.push_back(n->data);
	in_orden(n->left, vec);
	
	

}
int deep(node *n, bool *flag)
{
	if(n==NULL)
		return 0;
	int left=deep(n->left, flag);
	int right=deep(n->right, flag);
	if(abs(left-right)>1)
		*flag=false;
	return max(left,right)+1;
}
void clean(node *n)
{
	if(n==NULL)
		return;

	clean(n->left);	
	clean(n->right);
	
	delete n;
}
int main()
{
	int n,assis;
	cin>>n;
	node * root=new(node);
	for(int i=0; i<n; i++)
	{
		cin>>assis;
		put(root, assis);
	}
	vector<int> vec, dos;
	int frac=~0;
	for(int i=0; i<32; i++)
	{
		//cout<<i<<endl;
		if((1<<i) & frac)
			dos.push_back(1);
		else
			dos.push_back(0);
	}

	for(int i=dos.size()-1; i>=0; i--)
		cout<<dos[i];
	cout<<endl;
	in_orden(root, vec);
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	bool flag=true;
	cout<<"high: "<<deep(root, &flag)<<endl;
	cout<<"ban: "<<flag<<endl;
	clean(root);

}