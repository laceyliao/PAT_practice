/*
1151 LCA in a Binary Tree 
The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.
Given any two nodes in a binary tree, you are supposed to find their LCA.
Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (¡Ü 1,000), 
the number of pairs of nodes to be tested; and N (¡Ü 10,000), the number of keys in the binary tree, respectively. 
In each of the following two lines, N distinct integers are given as the inorder and preorder traversal sequences 
of the binary tree, respectively. It is guaranteed that the binary tree can be uniquely determined by the input sequences. 
Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.
Output Specification:
For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. 
But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is 
not found in the binary tree, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..

Sample Input:
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99

Sample Output:
LCA of 2 and 6 is 3.
8 is an ancestor of 1.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

const int MAX=10005;
map<int,int> isexist;
int M,N;
int inorder[MAX],preorder[MAX];

struct node{
	int val;
	node *left;
	node *right;
};

node* buildTree(int prel, int inl,int n)
{
	if(n<1) return NULL;
//	cout<<n<<endl;
	node *tree = new node();
	tree->val=preorder[prel];
//	cout<<preorder[prel]<<endl;
	int i=0;
	for(;i<n;i++)
	{
		if(inorder[inl+i] == preorder[prel]) break;
	}
	tree->left = buildTree(prel+1,inl,i);
	tree->right = buildTree(prel+i+1,inl+i+1,n-i-1);
	return tree;
}

node* LCA(node *tree, int u, int v)
{
	if(tree)
	{
		if(tree->val==u || tree->val==v) return tree;
		node *l=LCA(tree->left,u,v);
		node *r=LCA(tree->right,u,v);
		if(l!=NULL && r!=NULL) return tree;
		return l==NULL?r:l;
	}
	else return NULL;
}
void delTree(node *tree)
{
	if(tree->left!=NULL) delTree(tree->left);
	if(tree->right!=NULL ) delTree(tree->right);
	delete tree;
}
int main()
{
	cin>>M>>N;
	int u,v;
	for(int i=0;i<N;i++)
	{
		cin>>inorder[i];
		isexist[inorder[i]]=1;
	}
	for(int i=0;i<N;i++) 
		cin>>preorder[i];
	
	node *tree=buildTree(0,0,N);
	while(M--)
	{
		cin>>u>>v;
		if(isexist[u]==0 && isexist[v]==0) cout<<"ERROR: "<<u<<" and "<<v<<" are not found."<<endl;
		else if(isexist[u]==0) cout<<"ERROR: "<<u<<" is not found."<<endl;
		else if(isexist[v]==0) cout<<"ERROR: "<<v<<" is not found."<<endl;
		else{
			node *tmp=LCA(tree,u,v);
			if(tmp->val==u) cout<<u<<" is an ancestor of "<<v<<"."<<endl;
			else if(tmp->val==v) cout<<v<<" is an ancestor of "<<u<<"."<<endl;
			else{
				cout<<"LCA of "<<u<<" and "<<v<<" is "<<tmp->val<<"."<<endl;
			}
		}
	}
	delTree(tree);
	return 0;
}
