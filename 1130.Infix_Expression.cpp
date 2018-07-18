/*
1130 Infix Expression (25)£¨25 ·Ö£©
Given a syntax tree (binary), you are supposed to output the corresponding infix expression, 
with parentheses reflecting the precedences of the operators.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N ( <= 20 ) 
which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of 
a node (the i-th line corresponds to the i-th node) in the format:
data left_child right_child
where data is a string of no more than 10 characters, left_child and right_child are the indices of this 
node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is 
represented by -1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.

  Figure 1 Figure 2

Output Specification:
For each case, print in a line the infix expression, with parentheses reflecting the precedences 
of the operators. Note that there must be no extra parentheses for the final expression, as is shown 
by the samples. There must be no space between any symbols.
Sample Input 1:
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
Sample Output 1:
(a+b)*(c*(-d))
Sample Input 2:
8
2.35 -1 -1
* 6 1
- -1 4
% 7 8
+ 2 3
a -1 -1
str -1 -1
871 -1 -1
Sample Output 2:
(a*2.35)+(-(str%871))
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<memory.h>
using namespace std;
const int MAX=25;

struct node{
	string value;
	int left,right;
	node():left(-1),right(-1){}
};

vector<node> tree(MAX);
int father[MAX],flag;

void TreeTravel(int root)
{
	if(root ==-1)
		return ;

	if( root!=flag && (tree[root].left!=-1 || tree[root].right != -1))
		cout<<"(";
	TreeTravel(tree[root].left);
	cout<<tree[root].value;
	TreeTravel(tree[root].right);
	if(root!=flag && (tree[root].left!=-1 || tree[root].right != -1))
		cout<<")";
}
int main()
{
	int n;
	scanf("%d",&n);
	string input;
	memset(father,0,sizeof(father));
	for( int i=1;i<=n;i++ ){
		cin>>tree[i].value>>tree[i].left>>tree[i].right;

		if(tree[i].left >0) father[tree[i].left] = i;
		if(tree[i].right >0) father[tree[i].right] = i;
	
	}
	flag=1;
	while(father[flag]!=0) flag++;
	
	TreeTravel(flag);
	return 0;
}
