/*
1135. Is It A Red-Black Tree (30)

There is a kind of balanced binary search tree named red-black tree in the data structure. 
It has the following 5 properties:
(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes. 
For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.

For each given binary search tree, you are supposed to tell if it is a legal red-black tree.
Input Specification: 
Each input file contains several test cases. The first line gives a positive integer K (<=30) 
which is the total number of cases. For each case, the first line gives a positive integer N (<=30), 
the total number of nodes in the binary tree. The second line gives the preorder traversal sequence 
of the tree. While all the keys in a tree are positive integers, we use negative signs to represent 
red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to 
the trees shown in Figure 1, 2 and 3.

Output Specification: 
For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.

Sample Input:
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17

Sample Output:
Yes
No
No
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int K,N,num;
const int MAX=30;
int data[MAX];
bool first,IsRBTree;

struct node{
	int value;
	node *left;
	node *right;
	node(int d):value(d){}
};

node* buildTree(int left, int right)
{
	if(left > right) return NULL;
	
	node *tree = new node(data[left]);
	int nextL=left+1;
	for(; nextL<= right; nextL++)
	{
		if(abs(data[nextL]) > abs(data[left]) )
			break;
	}
	tree->left = buildTree(left+1, nextL-1);
	tree->right = buildTree(nextL, right);
	return tree;
}

void delTree(node *tree)
{
	if(tree == NULL) return ;
	delTree(tree->left);
	delTree(tree->right);
	delete tree;
	tree = NULL;
}

void dfs(node *tree, int cnt)
{
	if(!IsRBTree) return ;
	if(tree == NULL)
	{
		if(first)
		{
			num = cnt;
			first = false;
		}
		else if(cnt != num)
			IsRBTree=false;
		return ;
	}
	if(tree->value >0) cnt++;
	else {
		if(tree->left!=NULL && tree->left->value < 0 ) IsRBTree = false;
		if(tree->right!=NULL && tree->right->value < 0) IsRBTree = false;
	}
	dfs(tree->left, cnt);
	dfs(tree->right, cnt);
}

int main()
{
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d",&N);
		first=true;
		num=0;
		for(int i=0; i<N ;i++)
			scanf("%d",&data[i]);
		
		node *tree = buildTree(0,N-1);
		IsRBTree = data[0]>0 ? true :false;
		dfs(tree,0);
		if(IsRBTree) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		delTree(tree);
	}
	return 0;
}
