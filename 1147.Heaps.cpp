#include<iostream>
#include<vector>

using namespace std;
const int MAX=1001;
int tree[MAX];
int M,N;

bool IsMaxHeap()
{
	int i=N/2;
	while(i>0)
	{
		int child=2*i;
		if(child!=N && tree[child]<tree[child+1] ) ++child;
		if(tree[i] < tree[child]) return false;
		--i;
	}
	return true;
}

bool IsMinHeap()
{
	int i=N/2;
	while(i>0)
	{
		int child=2*i;
		if(child!=N && tree[child]>tree[child+1] ) ++child;
		if(tree[i] > tree[child]) return false;
		--i;
	}
	return true;
}

void postOrder(vector<int> &res,int i)
{
	if(i>N) return ;
	else
	{
		postOrder(res,2*i);
		postOrder(res,2*i+1);
		res.push_back(tree[i]);
	}
}

int main()
{
	cin>>M>>N;
	for(int i=0;i<M;i++)
	{
		int data;
		for(int j=1;j<=N;j++)
		{
			cin>>data;
			tree[j]=data;
		}
		if( IsMaxHeap() )  cout<<"Max Heap"<<endl;
		else if(IsMinHeap() ) cout<<"Min Heap"<<endl;
		else cout<<"Not Heap"<<endl;
		vector<int> res;
		postOrder(res,1);
		for(int j=0;j<N;j++)
		{
			if(j==0) cout<<res[j];
			else cout<<" "<<res[j];
		}
		cout<<endl;
	}
	return 0;
}
