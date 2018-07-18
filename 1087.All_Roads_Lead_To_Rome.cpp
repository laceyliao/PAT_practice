#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<map>
using namespace std;

const int MAX=202;
const int INF=9999999;
int N,K,road = 0;
int graph[MAX][MAX];

string begin_city;

map<string,int>  city;
map<int,string>  cityID;

vector<int> pre(MAX,-1);
vector<bool> visited(MAX,false);
vector<int> happiness(MAX,0);
vector<int> happyCnt(MAX,0);
vector<int> cityCnt(MAX,1);
vector<int> dist(MAX,INF);
vector<int> path(MAX,1);
list<string>  result;

int FindMin()
{
	int tmp=-1;
	int min=INF;
	for(int i=0;i<N;i++)
	{
		if(!visited[i] && dist[i]<min)
		{
			min=dist[i];
			tmp=i;
		}
	}
	return tmp;
}

void Dijkstra(int start, int end)
{
	int v;
	visited[start] = true;
	
	while(true)
	{
		v=FindMin();
		if(v==-1) return;
		visited[v] = true;
		
		for(int i=0;i<N;i++)
		{
			if(!visited[i])	
			{
				if(dist[v]+graph[v][i] < dist[i])
				{
					pre[i] = v;
					dist[i] = dist[v]+graph[v][i];
					happyCnt[i] = happyCnt[v] + happiness[i]; 
					cityCnt[i] = cityCnt[v]+1;
					path[i] = path[v];
				}
				else if(dist[v]+graph[v][i] == dist[i])
				{
					path[i] += path[v];
					if( happyCnt[v] + happiness[i] > happyCnt[i] )
					{
						happyCnt[i] = happyCnt[v] + happiness[i];
						cityCnt[i] = cityCnt[v]+1;
						pre[i] = v;
					}
					else if(happyCnt[v] + happiness[i] == happyCnt[i])
					{
						if(cityCnt[v]+1 < cityCnt[i])
						{
							cityCnt[i] = cityCnt[v]+1;
							pre[i] = v;
						}
					}
					
				}
			}
		}	
	}
}
int main()
{
	string town,c1,c2;
	int hap,t1,t2,dis;
	
	cin>>N>>K>>begin_city;
	city[begin_city]=0;
	cityID[0] = begin_city;
	happiness[0]=0;
	pre[0]=0;
	
	for(int i=1;i<N;i++)
	{
		cin>>town>>hap;
		city[town] = i;
		cityID[i] = town;
		happiness[i]=hap;
	}

	int end=city["ROM"];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			graph[i][j]=INF;
	}
	for(int i=0;i<K;i++)
	{
		cin>>c1>>c2>>dis;
		t1=city[c1];
		t2=city[c2];
		graph[t1][t2]=dis;
		graph[t2][t1]=dis;
	}
	
	for(int i=1;i<N;i++)
	{
		if(graph[0][i] < INF)
		{
			dist[i]=graph[0][i];
			pre[i]=0;
			happyCnt[i]=happiness[i];
		}
	}
	Dijkstra(0,end);
	
	int tmp=end;
	while(pre[tmp]!=tmp)
	{
		result.push_front(cityID[tmp]);
		tmp=pre[tmp];
	}
	cout<<path[end]<<" "<<dist[end]<<" "<<happyCnt[end]<<" "<<happyCnt[end]/cityCnt[end]<<endl;
	cout<<begin_city;
	
	list<string>::iterator ij=result.begin();
	for(; ij != result.end();ij++)
		cout<<"->"<<*ij;
	return 0;
}

