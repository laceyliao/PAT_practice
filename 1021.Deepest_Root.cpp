/*
1021. Deepest Root (25)

CHEN, Yue
A graph which is connected and acyclic can be considered a tree. The height of the tree 
depends on the selected root. Now you are supposed to find the root that results in a 
highest tree. Such a root is called the deepest root.
Input Specification: 
Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. 
Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
Output Specification: 
For each test case, print each of the deepest roots in a line. If such a root is not unique, 
print them in increasing order of their numbers. In case that the given graph is not a tree, 
print "Error: K components" where K is the number of connected components in the graph.
Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/
#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;

const int MAX = 10001;
vector<list<int> > adjnode;
vector<bool> visited;
vector<int> pre;
int N,components,deep=0;

set<int> tree;

void DFS(int point,int level)
{
	if(level>deep)
	{
		tree.clear();
		tree.insert(point);
		deep = level;
	}
	else if(level == deep)
		tree.insert(point);
	
	list<int>::iterator it = adjnode[point].begin();
	for(; it != adjnode[point].end();it++)
	{
		if( !visited[*it])
		{
			visited[*it] = true;
			DFS(*it,level+1);
			visited[*it] = false;
		}
	}
}
int root(int x)
{
	while(pre[x]!=x) {
		x = pre[x];
	}
	return x;
}
void merge(int x,int y)
{
	int fa = root(x);
	int fb = root(y);
	if(fa!=fb)
	{
		pre[fa] = fb;
		components--;
	}
}
int main()
{
	int a,b;
	set<int>::iterator item;
	cin>>N;
	components = N;
	adjnode.resize(N+1);
	pre.resize(N+1);
	visited.resize(N+1,false);
	for(int i=1;i<=N;i++)
	{
		pre[i] = i;
	}
	for(int i=1;i<N;i++)
	{
		cin>>a>>b;
		adjnode[a].push_back(b);
		adjnode[b].push_back(a);
		merge(a,b);
	}
	if(components!=1)
	{
		cout<<"Error: "<<components<<" components"<<endl;
		return 0;
	}
	visited[1] = true;
	DFS(1,1);
	visited[1] = false;
	
	set<int>  alltree = tree;
	
	int point = (*tree.begin());
	visited[point] = true;
	DFS(point,1);
//	visited[point] = false;
	
	item = tree.begin();
	for(;item!=tree.end();item++)
		alltree.insert(*item);
	
	item = alltree.begin();
	for(;item!=alltree.end();item++)
		cout<<*item<<endl;
		
	return 0;
}
