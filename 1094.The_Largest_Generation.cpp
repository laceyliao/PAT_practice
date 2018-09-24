/*
1094 The Largest Generation 
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same 
level belong to the same generation. Your task is to find the generation with the largest 
population.
Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (<100) 
which is the total number of family members in the tree (and hence assume that all the members 
are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a family member, K (>0) is the number of his/her 
children, followed by a sequence of two-digit ID's of his/her children. For the sake of 
simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the largest population number and the level of the 
corresponding generation. It is assumed that such a generation is unique, and the root 
level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

Sample Output:
9 4
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX=102;
vector<int> parent(MAX,-1),child[MAX];
queue<int> q1,q2;

int main()
{
	int N,M,ID,K,kid,root=-1;
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		cin>>ID>>K;
		while(K--)
		{
			cin>>kid;
			parent[kid]=ID;
			child[ID].push_back(kid);
		}
	}
	for(int i=1;i<=N;i++)
		if(parent[i]==-1){
			root = i;
			break;
		}
	q1.push(root);
	int level=2,maxlevel=1,maxpop=1,cnt=0;
	while(!q1.empty() || !q2.empty())
	{
		if(!q1.empty()){
			while(!q1.empty())
			{
				root=q1.front();
				q1.pop();
				int l=child[root].size();
				for(int i=0; i < l ;i++)
				{
					q2.push(child[root][i]);
					cnt++;
				}
			}
		}
		else{
			while(!q2.empty())
			{
				root=q2.front();
				q2.pop();
				int l=child[root].size();
				for(int i=0;i<l;i++)
				{
					q1.push(child[root][i]);
					cnt++;
				}
			}
		}
		if(cnt>maxpop)
		{
			maxpop=cnt;
			maxlevel=level;
		}
		cnt=0;
		level++;
	}
	cout<<maxpop<<" "<<maxlevel<<endl;
	return 0;
}
