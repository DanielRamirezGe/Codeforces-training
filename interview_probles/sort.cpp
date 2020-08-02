#include <iostream> 
#include <vector>
using namespace std;
struct node{
	int data;
	node *left=NULL;
	node *right=NULL;
};
node* build(int left, int right, vector <int> vec)
{
	if(right<left )
		return NULL;
	if(left==right)
	{
		node *current=new(node);
		current->data= vec[left];
		return current;
	}
	int medd=left+(right-left)/2;
	node *current=new(node);
	current->data=vec[medd];
	current->left=build(left, medd-1, vec);
	current->right=build(medd+1,right, vec);
	return current;
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
void pre_orden(node* n)
{
	if(n==NULL)
		return;
	cout<<"el nodo con : "<<n->data<<endl;
	if(n->left!=NULL)
		cout<<"   hijo izquierdo: "<<(n->left)->data<<endl;
	else
		cout<<"   hijo izquierdo: NULL"<<endl;
	if(n->right!=NULL)
		cout<<"   hijo izquierdo: "<<(n->right)->data<<endl;
	else
		cout<<"   hijo izquierdo: NULL"<<endl;
	pre_orden(n->left);
	pre_orden(n->right);


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
	int n, assis;
	vector <int> vec;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>assis;
		vec.push_back(assis);
	}
	node *root=build(0, vec.size()-1, vec);
	pre_orden(root);
	bool flag=true;
	cout<<deep(root, &flag)<<endl;
	cout<<"bandera: "<<flag<<endl;
	clean(root);
}