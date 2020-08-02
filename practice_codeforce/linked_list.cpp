#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next=NULL;
};
node * fund(node *list, int k)
{
	node *first=list;
	node *second=list;
	for(int i=0; i<k; i++)
	{
		if(first->next==NULL)
			return NULL;
		first=first->next;
		cout<<first->data <<" "<<first->next<<endl;

	}
	while(first->next!=NULL)
	{
		second=second->next;
		first=first->next;
	}
	return second;
}
int main()
{
	node *root=new(node);
	node *concurrent=root;
	int num,n;
	cin>>num;
	for(int i=0; i<num; i++)
	{
		cin>>n;
		node *x=new(node);
		x->data=n;
		concurrent->next=x;
		concurrent=x;
	}
	int k;
	cin>>k;
	node *yes=fund(root, k);
	if(yes==NULL)
		cout<<"bigest than the list"<<endl;
	else
		cout<<yes->data;
	concurrent=root;
	while(concurrent!=NULL)
	{
		concurrent=root->next;
		delete(root);
		root=concurrent;
	}


}