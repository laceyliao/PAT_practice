#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int N;
stack<int> Tree;
vector<int> preorder,inorder,postorder(31);

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
	while(count<N)
	{
		cin>>op;
		if(op=="Push")
		{
			cin>>num;
			Tree.push(num);
			preorder.push_back(num);
		}
		else {
			int tmp = Tree.top();
			inorder.push_back(tmp);
			Tree.pop();
			count++;
		}		
	}

	solve(0,0,0,N);
	cout<<postorder[0];
	for(int i=1;i<N;i++)
		cout<<" "<<postorder[i];
	return 0;	
}
