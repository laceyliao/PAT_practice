/*
1150 Travelling Salesman Problem 
The "travelling salesman problem" asks the following question: "Given a list of cities and 
the distances between each pair of cities, what is the shortest possible route that visits 
each city and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, 
important in operations research and theoretical computer science. (Quoted from "https://en.wikipedia.org/wiki/Travelling_salesman_problem".)
In this problem, you are supposed to find, from a given list of cycles, the one that is the closest to the solution of a travelling salesman problem.
Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N¡Ü200), 
the number of cities, and M, the number of edges in an undirected graph. Then M lines follow, 
each describes an edge in the format City1 City2 Dist, where the cities are numbered from 1 to N and the 
distance Dist is positive and is no more than 100. The next line gives a positive integer K which is the 
number of paths, followed by K lines of paths, each in the format:
n C1 C2...Cn
where n is the number of cities in the list, and Ci's are the cities on a path.
Output Specification:
For each path, print in a line Path X: TotalDist (Description) where X is the index (starting from 1) 
of that path, TotalDist its total distance (if this distance does not exist, output NA instead), and Description is one of the following:
TS simple cycle if it is a simple cycle that visits every city;
TS cycle if it is a cycle that visits every city, but not a simple cycle;
Not a TS cycle if it is NOT a cycle that visits every city.
Finally print in a line Shortest Dist(X) = TotalDist where X is the index of the cycle that is the 
closest to the solution of a travelling salesman problem, and TotalDist is its total distance. It is guaranteed that such a solution is unique.
Sample Input:
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
7
7 5 1 4 3 6 2 5
7 6 1 3 4 5 2 6
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 2 5 4 3 1
7 6 3 2 5 4 1 6

Sample Output:
Path 1: 11 (TS simple cycle)
Path 2: 13 (TS simple cycle)
Path 3: 10 (Not a TS cycle)
Path 4: 8 (TS cycle)
Path 5: 3 (Not a TS cycle)
Path 6: 13 (Not a TS cycle)
Path 7: NA (Not a TS cycle)
Shortest Dist(4) = 8
*/
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

const int MAX=202;
int graph[MAX][MAX];
bool visited[MAX];

int main()
{
	int N,M,n,K,a,b,c;
	scanf("%d %d",&N,&M);
	memset(graph,0,sizeof(graph));
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		graph[a][b]=c;
		graph[b][a]=c;
	}
	cin>>K;
	int index,mindist=9999999;
	for(int j=1;j<=K;j++)
	{
		scanf("%d",&n);
		bool isSimple=true,isTS=true,isConnect=true;
		memset(visited,false,sizeof(visited));
		if(n < (N+1)) isTS=false;
		
		else if(n > (N+1)) isSimple=false;
		cin>>a;
		int dist=0,begin=a;
		for(int i=1;i<n;i++)
		{
			cin>>b;
			if(!visited[b]) visited[b]=true;
			else isSimple=false;
			if(graph[a][b]>0) dist+=graph[a][b];
			else isConnect=false;
			a=b;
		}
		if(begin!=a) isTS=false;
		for(int i=1;i<=N;i++)
		{
			if(!visited[i]) {
				isTS=false;
				break;
			}
		}
		if(!isConnect)	cout<<"Path "<<j<<": NA (Not a TS cycle)"<<endl;
		else if(!isTS) cout<<"Path "<<j<<": "<<dist<<" (Not a TS cycle)"<<endl;
		else if(!isSimple){
			cout<<"Path "<<j<<": "<<dist<<" (TS cycle)"<<endl;
			if(dist<mindist)
			{
				mindist=dist;
				index=j;
			}
		} 
		else {
			cout<<"Path "<<j<<": "<<dist<<" (TS simple cycle)"<<endl;
			if(dist<mindist)
			{
				mindist=dist;
				index=j;
			}
		}
	}
	cout<<"Shortest Dist("<<index<<") = "<<mindist<<endl;
	return 0;
}
