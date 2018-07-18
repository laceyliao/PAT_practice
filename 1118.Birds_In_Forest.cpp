#include<iostream>
#include<vector>

using namespace std;

const int MAX=10002;
int N,K,components=0;
vector<int> pre(MAX);
vector<bool> IsIn(MAX,false);

int root(int x)
{
	int tmp=x;
	while(pre[x]!=x)
		x=pre[x];
	
	while(tmp != pre[tmp])
	{
		int z=tmp;
		tmp=pre[tmp];
		pre[z] = x;
	}
	return x;
}

void unite(int x,int y)
{
	int fa=root(x);
	int fb=root(y);
	if(fa != fb)
	{
		pre[fb] = fa;
		components++;
	}
}
int main()
{
	cin>>N;
	int data,father,max=0;
	int b1,b2,queries;
	for(int i=0;i<MAX;i++)
		pre[i]=i;
		
	for(int i=0;i<N;i++)
	{
		cin>>K>>father;
		IsIn[father] = true;
		for(int j=1;j<K;j++)
		{
			cin>>data;
			IsIn[data] = true;
			unite(father,data);
		}
	}
	for(int i=1;i<MAX;i++)
	{
		if(!IsIn[i]){
			max = i-1;
			break;
		}
	}
	cout<<max-components<<" "<<max<<endl;
	cin>>queries;
	for(int i=0;i<queries;i++)
	{
		cin>>b1>>b2;
		if( root(b1) == root(b2) )
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
