/*
1030. Travel Plan (30)

CHEN, Yue
A traveler's map gives the distances between cities along the highways, together with the cost of 
each highway. Now you are supposed to write a program to help a traveler to decide the shortest 
path between his/her starting city and the destination. If such a shortest path is not unique, 
you are supposed to output the one with the minimum cost, which is guaranteed to be unique. 
Input Specification: 
Each input file contains one test case. Each case starts with a line containing 4 positive 
integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are 
numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination 
cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
City1 City2 Distance Cost 
where the numbers are all integers no more than 500, and are separated by a space. 
Output Specification: 
For each test case, print in one line the cities along the shortest path from the starting point to 
the destination, followed by the total distance and the total cost of the path. The numbers must be 
separated by a space and there must be no extra space at the end of output. 

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

Sample Output
0 2 3 3 40
*/
#include<iostream>
#include<vector>
#include<list>

using namespace std;

const int INF = 999999;

struct Node{
	int dist,cost,pre;
	Node():dist(INF),cost(INF),pre(-1){}
};

struct Edge{
	int end,dist,cost;
	Edge(int a,int b,int c):end(a),dist(b),cost(c){}
};

int N,M,S,D;
vector<list<Edge> > adjedge;
vector<bool> visited;
vector<Node>city;
list<int> path;

int FindMin()
{
    int min=INF,index=-1;
    for(int i=0;i<N;i++)
    {
        if(!visited[i] && city[i].dist<min)
        {
            min=city[i].dist;
            index=i;
        }
    }
    return index;
}

void Dijkstra(int start,int end)
{
	visited.resize(N,false);

	city.resize(N);//the distance between start city and any other citys is INF
	city[S].dist = 0; 
	city[S].cost = 0;
	city[S].pre = S;
	
	while(true)
	{
		int w = FindMin();//find the shortest path
		if(w == -1) return;
		visited[w] = true;
		list<Edge>::iterator it = adjedge[w].begin();
		for(; it != adjedge[w].end() ;it++)
		{
			int v=it->end;
			int dist = it->dist;
			int cost = it->cost;
			if(!visited[v])
			{
				if(city[w].dist+dist < city[v].dist )
				{
					city[v].dist = city[w].dist + dist;
					city[v].cost = city[w].cost + cost;
					city[v].pre = w;
				}
				else if(city[w].dist+dist == city[v].dist && city[v].cost > city[w].cost + cost)
				{
					city[v].cost = city[w].cost + cost;
					city[v].pre = w;		
				}
			}
		} 
	}
}
int main()
{
    int a,b,distance,fare;

	cin>>N>>M>>S>>D;
	adjedge.resize(N);
	for(int i=0;i<M;i++)
	{
		cin>>a>>b>>distance>>fare;
		adjedge[a].push_back(Edge(b,distance,fare));
		adjedge[b].push_back(Edge(a,distance,fare));
	}
    Dijkstra(S,D);
	int tmp=D;
	path.push_front(D);
	while(city[tmp].pre != tmp)
	{
		path.push_front(city[tmp].pre);
		tmp = city[tmp].pre;
	}
	list<int>::iterator it=path.begin();
	for(; it != path.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<city[D].dist<<" "<<city[D].cost;
    return 0;
}
