#include  <iostream> 
#include <algorithm>
using namespace std;
int l_b(int n,int arr[], int serch)
{
	
	int left=0, right=n-1;
	int medd=left+(right-left)/2;
	while(left<right)
	{
		if(left+1==right)
		{
			if(arr[left]!=serch and arr[right]==serch)
				return right;
			if(arr[right]<serch)	
				return right;
			return left;
		}

		if(serch==arr[medd])
			right=medd;
		if(serch<arr[medd])
			right=medd-1;
		if(serch>arr[medd])
			left=medd;
		medd=left+(right-left)/2;
	}
	return left;	
	
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int q,serch;
	cin>>q;

	for(int i=0; i<q; i++)
	{
		cin>>serch;
		int pl=l_b(n,arr,serch );
		cout<<pl<<"  -- "<<arr[pl]<<endl;	
	}
}