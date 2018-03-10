/*
1102. Invert a Binary Tree (25)

CHEN, Yue
The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of 
nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and 
gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair 
of children are separated by a space.
Output Specification: 
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted 
tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1

*/

#include<iostream>
#include<queue>

using namespace std;

struct Node{
	int num,left,right;
	Node():num(-1),left(-1),right(-1) {}
};

Node Tree[12];
bool Isroot[12];
bool Isfirst;

void Inorder(int root)
{
	if(Tree[root].left != -1)
		Inorder(Tree[root].left);
		
	if(Isfirst) {
		cout<<root;
		Isfirst = false;
	}
	else cout<<" "<<root;
	
	if(Tree[root].right !=-1)
		Inorder(Tree[root].right);	
}

int main()
{
	int N,root,tmp;
	char l, r;
	cin>>N;
	for(int i=0;i<N;i++)
		Isroot[i] = true;
	
	for(int i=0;i<N;i++)
	{
		cin>>r>>l;
		Tree[i].num = i;
		if(l != '-') {
			tmp = l-'0';
			Tree[i].left = tmp;
			Isroot[tmp] = false;
		}
		if(r != '-') {
			tmp = r-'0';
			Tree[i].right = tmp;
			Isroot[tmp] = false;
		}
	}
	for(int i=0; i<N;i++)
	{
		if( Isroot[i])
		{
			root = i;
			break;
		}
	}
	
	queue<Node> qtree;
	qtree.push(Tree[root]);
	Isfirst = true;
	while(!qtree.empty())
	{
		Node item = qtree.front();
		qtree.pop();
		if(Isfirst) {
			cout<<item.num;
			Isfirst = false;
		}
		else cout<<" "<<item.num;
		
		if(item.left != -1)
			qtree.push( Tree[item.left] );
		if(item.right != -1)
			qtree.push( Tree[item.right] );
	}
	cout<<endl;
	
	Isfirst = true;
	Inorder(root);
	
	return 0;
}
