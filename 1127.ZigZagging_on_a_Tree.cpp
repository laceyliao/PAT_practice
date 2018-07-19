/*
1127 ZigZagging on a Tree£¨30 ·Ö£©
Suppose that all the keys in a binary tree are distinct positive integers. 
A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. 
And it is a simple standard routine to print the numbers in level-order. However, if you think the 
problem is too simple, then you are too naive. This time you are supposed to print the numbers in 
"zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating 
between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (¡Ü30), 
the total number of nodes in the binary tree. The second line gives the inorder sequence and the third 
line gives the postorder sequence. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must 
be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1

Sample Output:
1 11 5 8 17 12 20 15
*/
#include<iostream>
#include<deque>
using namespace std;

int N,index=0;
const int MAX=31;

struct node{
	int data;
	struct node *left,*right;
	node(){
		data=0;
		left=NULL;
		right=NULL;
	}
};

int inorder[MAX],postorder[MAX];

node* buildTree(int start, int end)
{
	index--;
	node *p = new node;
	int i;
	for(i=0;i<N;i++)
		if(inorder[i]==postorder[index]) break;
	p->data = postorder[index];
	
	if(i+1<end) p->right=buildTree(i+1,end);
	if(start<i) p->left=buildTree(start,i);
	return p;
}

void BFS(node *root){
	deque<struct node> q;
	q.push_back(*root);
	int times=0,cnt=1,now_cnt=0;
	cout<<root->data;
	while(!q.empty()){
		if(q.front().left!=NULL) {
			q.push_back(*q.front().left);
			now_cnt++;
		}
		if(q.front().right){
			q.push_back(*q.front().right);
			now_cnt++;
		}
		q.pop_front();
		cnt--;
		if(cnt==0){
			times++;
			if(times%2==1){
				for(int i=0;i<q.size();i++)
					cout<<" "<<q.at(i).data;
			}
			else 
				for(int i=q.size()-1;i>=0;i--)
					cout<<" "<<q.at(i).data;
			cnt=now_cnt;
			now_cnt=0;
		}
	}
}

void delTree(node *tree){
	if(tree == NULL) return ;
	delTree(tree->left);
	delTree(tree->right);
	delete tree;
	tree = NULL;
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>inorder[i];
	
	for(int i=0;i<N;i++)
		cin>>postorder[i];
	
	index=N;
	node *root=buildTree(0,N);
	BFS(root);
	delTree(root);
	return 0;
}
