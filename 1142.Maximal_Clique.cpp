#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int MAX=202;
int graph[MAX][MAX];
int query[MAX];
int main()
{
	int NV,NE,M,K;
	int s,e;
	scanf("%d %d",&NV,&NE);
	for(int i=1;i<=NV;i++)
		for(int j=1;j<=NV;j++)
			graph[i][j]=0;
	
	for(int i=0;i<NE;i++)
	{
		cin>>s>>e;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	cin>>M;
	while(M--)
	{
		cin>>K;
		vector<bool> IsIn(NV+1,false);
		for(int j=0;j<K;j++)
		{
			cin>>query[j];
			IsIn[query[j]] = true;
		}
		
		bool flag = true;
		
		for(int i=0;i<K-1;i++)
		{
			for(int j=i+1;j<K;j++)
			{
				int a=query[i],b=query[j];
				if(graph[a][b]!=1) {
					flag = false;
					break;
				}
			}
		}
		if(!flag) {
			cout<<"Not a Clique"<<endl;
			continue;
		}
		flag = true;
		for(int i=1;i<=NV;i++)
		{
			if(!IsIn[i]) {
				int cnt=0;
				for(int j=0;j<K;j++)
				{
					int a=i,b=query[j];
					if(graph[a][b]==1) cnt++; 
				}
				if(cnt==K){
					flag = false;
					break;
				}
			}
		}
		if(!flag) cout<<"Not Maximal"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
