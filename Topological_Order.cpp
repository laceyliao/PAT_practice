#include<iostream>
#include<vector>
#include<list>

using namespace std;
const int MAX=1001;
int N,M,K;
vector<list<int> > matrix(MAX);
vector<int> inDegree(MAX,0);
vector<int> tmpDegree(MAX,0);
vector<int> result;

void CopyDegree()
{
	for(int i=1;i<=N;i++)
		tmpDegree[i]=inDegree[i];
}

bool IsTopoOrder(vector<int>  &data)
{
	for(int i=0;i<data.size();i++)
	{
		int v=data[i];
		if(tmpDegree[v] ==0 )
		{
			list<int>::iterator it=matrix[v].begin();
			for(; it!=matrix[v].end();it++)
			{
				tmpDegree[*it]--;
			}
		}
		else return false;
	}
	return true;
}

int main()
{
	cin>>N>>M;
	int start,end;
	
	for(int i=0;i<M;i++)
	{
		cin>>start>>end;
		matrix[start].push_back(end);
		inDegree[end]++;
	}
	cin>>K;
	for(int i=0;i<K;i++)
	{
		CopyDegree();
		vector<int> data;
		int tmp;
		for(int j=0;j<N;j++)
		{
			cin>>tmp;
			data.push_back(tmp);			
		}
		if( !IsTopoOrder(data) ) {
			result.push_back(i);
		}	
	}
	for(int i=0;i<result.size();i++)
	{
		if(i==0) cout<<result[i];
		else cout<<" "<<result[i];
	}
	return 0;
 } 
