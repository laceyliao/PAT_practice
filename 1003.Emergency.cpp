/*
1003. Emergency (25)

As an emergency rescue team leader of a city, you are given a special map of your country. 
The map shows several scattered cities connected by some roads. Amount of rescue teams in 
each city and the length of each road between any pair of cities are marked on the map. When 
there is an emergency call to you from some other city, your job is to lead your men to the 
place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input
Each input file contains one test case. For each test case, the first line contains 4 positive 
integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the 
number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. 
The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. 
Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities 
connected by a road and the length of that road, respectively. It is guaranteed that there exists 
at least one path from C1 to C2. 
Output
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, 
and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed 
at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output
2 4
*/
#include<iostream>
using namespace std;

const int MAX = 501;
const int INF = 9999999;
int graph[MAX][MAX],worker[MAX];
int min_distance,maxteam,countroad,N;
bool visit[MAX];

void init(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		visit[i] = false;
		for(j=0;j<n;j++)
			graph[i][j]=INF;
	}
}

void dfs(int p,const int end,int dist,int team)
{
	if(p == end){
		if(dist<min_distance)
		{
			countroad = 1;
			min_distance = dist;
			maxteam = team;
		}
		else if(dist == min_distance)
		{
			countroad++;
			if(team>maxteam) maxteam = team;
		}
		return;
	}
	
	if(dist>min_distance) return;
	
	for(int i=0;i<N;i++)
	{
		if(!visit[i] && graph[p][i]!=INF)
		{
			visit[i]=true;
			dfs(i,end,dist+graph[p][i],team+worker[i]);
			visit[i]=false;
		}
	}
}

int main()
{
	int M,C1,C2,a,b,c;
	min_distance = INF;
	countroad=0;
	cin>>N>>M>>C1>>C2;
	init(N);
	
	for(int i=0;i<N;i++)
		cin>>worker[i];
		
	for(int i=0;i<M;i++)
	{
		cin>>a>>b>>c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	dfs(C1,C2,0,worker[C1]);
	cout<<countroad<<" "<<maxteam;
	return 0;
}
