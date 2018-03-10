//1018. Public Bike Management (30)

#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

const int INF=99999999;
const int MAX=501;
int bikes[MAX],pre[MAX];
int graph[MAX][MAX];
int CMAX,N,SP,M;
int sendbike=INF,takebike=INF,mindist=INF;
int cursend=0,curback=0;
bool visited[MAX];
list<int> bestpre;

void DFS(int begin, int end, int perfect, int dist)
{
	if(begin == end)
	{
		if(dist < mindist)
		{
			mindist = dist;
			sendbike = cursend;
			takebike = curback;
			bestpre.clear();
			bestpre.push_front(end);
			int tmp = end;
			while(pre[tmp] != tmp)
			{
				bestpre.push_front(pre[tmp]);
				tmp = pre[tmp];
			}
		}
		else if (dist == mindist)
		{
			if(cursend<sendbike || (cursend==sendbike) && (curback<takebike)) 
			{
				sendbike = cursend;
				takebike = curback;
				bestpre.clear();
				bestpre.push_front(end);
				int tmp = end;
				while(pre[tmp] != tmp)
				{
					bestpre.push_front(pre[tmp]);
					tmp = pre[tmp];
				}
			}
		}
		return;
	}
	
	if(dist> mindist) return ;
	
	for(int i=1; i<=N; i++)
	{
		if(visited[i]==false && graph[begin][i] < INF )
		{
			visited[i] = true;
			pre[i]=begin;
			int lastsend = cursend;
			int lastback = curback;
			//计算到达当前点的send和back数?
			if(bikes[i] + curback< perfect) {//bikes[i]<perfect
				cursend += perfect - bikes[i] - curback;
				curback = 0;
			}
			else {//bikes[i]>perfect
				curback += bikes[i]-perfect;
			}
			
			DFS(i,end,perfect, dist+graph[begin][i]);
			
			visited[i] = false;
			cursend = lastsend;
			curback = lastback;
		}
	}
}
int main()
{
	int si,sj,cost,need_bike;
	cin>>CMAX>>N>>SP>>M;
	for(int i=1; i<=N; i++)
		cin>>bikes[i];
	
	for(int i=0;i<=N;i++)//initial
	{
		visited[i] = false;
		pre[i]=-1;
		for(int j=0;j<=N;j++)
			graph[i][j]=INF;
	} 
	
	for(int i=0;i<M;i++)
	{
		cin>>si>>sj>>cost;
		graph[si][sj] = cost;
		graph[sj][si] = cost;
	}

	pre[0] = 0;

	DFS(0,SP,CMAX/2,0);
	
	list<int>::iterator it = bestpre.begin();
	cout<<sendbike<<" "<<*it;
	it++;
	for(; it!=bestpre.end() ; it++)
		cout<<"->"<<*it;	
	cout<<" "<<takebike<<endl;
	return 0;
}
