/*
1099. Build A Binary Search Tree (30)

CHEN, Yue
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key. 
The right subtree of a node contains only nodes with keys greater than or equal to the node's key. 
Both the left and right subtrees must also be binary search trees. 
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill 
these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to 
output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2. 

Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) 
which is the total number of nodes in the tree. The next N lines each contains the left and the right 
children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, 
and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. 
Finally N distinct integer keys are given in the last line.

Output Specification: 
For each test case, print in one line the level order traversal sequence of that tree. All the numbers 
must be separated by a space, with no extra space at the end of the line. 

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42

Sample Output:
58 25 82 11 38 67 45 73 42
*/

#include<iostream>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
	int value,left,right;
	Node():value(-1),left(-1),right(-1){}
};

Node Tree[101];
bool IsRoot[101];

void Inorder( list<int> & data, int root)
{
	if(Tree[root].left != -1)
	{
		Inorder(data,Tree[root].left);
	}
	Tree[root].value = data.front();
	data.pop_front();
	if(Tree[root].right != -1)
	{
		Inorder(data,Tree[root].right);
	}
}
int main()
{
	int N,root;
	cin>>N;
	list<int> treenode;
	int left,right;
	for(int i=0;i<N;i++)
	{
		IsRoot[i] = true;
	}
	for(int i=0;i<N;i++)
	{
		cin>>left>>right;
	//	Tree[i].id = i;
		if(left != -1) {
			Tree[i].left = left;
			IsRoot[left] = false;
		}
		if(right !=-1) {
			Tree[i].right = right;
			IsRoot[right] = false;
		}
	}
	
	int tmp;
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		treenode.push_back(tmp);
	}
	treenode.sort();
	
	for(int i=0;i<N;i++)
	{
		if(IsRoot) {
			root = i;
			break;	
		}
	}
	
	Inorder(treenode,root);
	
	queue<Node> qtree;
	qtree.push(Tree[root]);
	bool first = true;
	while(!qtree.empty())
	{
		Node item = qtree.front();
		qtree.pop();
		if(first) {
			cout<<item.value;
			first = false;
		}
		else cout<<" "<<item.value;
		if(item.left != -1) qtree.push(Tree[item.left]);
		if(item.right != -1) qtree.push(Tree[item.right]);
	}
	return 0;
}
