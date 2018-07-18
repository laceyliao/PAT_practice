#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int N;
stack<int> Tree;
vector<int> preorder,inorder,postorder(50002);

void solve(int preL,int inL, int postL,int n)
{
	if(n==0) return;
	if(n==1) {
		postorder[postL] = preorder[preL];
		return;
	}
	int root = preorder[preL];
	postorder[postL+n-1] = root;
	int i;
	for(i=0;i<n;i++)
		if(inorder[inL+i] == root)
			break;
	int L=i;
	int R=n-L-1;
	solve(preL+1,	inL,	postL,	L);
	solve(preL+1+L,inL+L+1,postL+L, R);
}
int main()
{
	string op;
	int num;
	cin>>N;
	int count=0;
	for(int i=0;i<N;i++)
	{
		cin>>num;
		preorder.push_back(num);	
	}
	for(int i=0;i<N;i++)
	{
		cin>>num;
		inorder.push_back(num);
	}
	solve(0,0,0,N);
	cout<<postorder[0];

	return 0;	
}
