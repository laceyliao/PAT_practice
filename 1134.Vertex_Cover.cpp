/*
1134. Vertex Cover (25)

A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. 
Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not. 
Input Specification: 
Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 104), 
being the total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the 
indices (from 0 to N-1) of the two ends of the edge. 
After the graph, a positive integer K (<= 100) is given, which is the number of queries. 
Then K lines of queries follow, each in the format:
Nv v[1] v[2] ... v[Nv] 
where Nv is the number of vertices in the set, and v[i]'s are the indices of the vertices. 
Output Specification: 
For each query, print in a line "Yes" if the set is a vertex cover, or "No" if not. 
Sample Input:
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
Sample Output:
No
Yes
Yes
No
No
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<string.h>
#include<cstdlib>
#include<map>
using namespace std;

const int MAX=10000;
vector<list<int> >  adj(MAX);
int visited[MAX];
map<int,int> Mindex;
int N,M,K,Nv;

void TestEdge(int p,int &cnt)
{
	list<int>::iterator it=adj[p].begin();
	for(; it!= adj[p].end(); it++)
	{
		int i;
		if(*it < p)
			i=(*it)*N+p;
		else  i=p*N + (*it);
		if(visited[Mindex[i] ]==0 )
		{
			visited[Mindex[i] ]=1;
			cnt++;
		}
	}
}
int main()
{
	scanf("%d %d",&N,&M);
	int a,b,p;
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		if(a<b) 
			Mindex[a*N+b]=i;
		else
			Mindex[b*N+a]=i;
	}
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d",&Nv);
		int cnt=0;
		memset(visited,0,sizeof(visited));
		while(Nv--)
		{
			scanf("%d", &p);
			TestEdge(p,cnt);
		}
		if(cnt<M)
			cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
