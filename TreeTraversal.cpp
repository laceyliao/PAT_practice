/*
1020. Tree Traversals (25)

CHEN, Yue
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and 
inorder traversal sequences, you are supposed to output the level order traversal sequence of the 
corresponding binary tree.

Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), 
the total number of nodes in the binary tree. The second line gives the postorder sequence and the third 
line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification: 
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. 
All the numbers in a line must be separated by exactly one space, and there must be no extra space at the 
end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 

*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> postorder(35),inorder(35),level(10000,-1);

void LevelTraversal(int root, int start, int end, int level_index)
{
	if(start > end) return; 
	
	int index=start;
	level[level_index] = postorder[root];
	while( index< end && inorder[index] != postorder[root])
		index++;
		
	LevelTraversal( root-end+index-1, start, index-1, level_index*2);
	LevelTraversal( root-1, index+1,end, level_index*2+1);
}
int main()
{
	int N;
	cin>>N;

	for(int i=1;i<=N; i++)
		cin>>postorder[i];
		
	for(int i=1;i<=N; i++)
		cin>>inorder[i];
		
	LevelTraversal(N,1,N,1);
	cout<<level[1];
	int count=1;
	for(int i=2;count<N;i++)
	{
		if(level[i] != -1)
		{
			cout<<" "<<level[i];
			count++;
		}
	}
	
	return 0;
}
