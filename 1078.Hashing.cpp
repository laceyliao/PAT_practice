#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const int MAX=100000;
int TSize;

vector<int> Isfilled(MAX,0);
vector<int> position(MAX,-1);

bool isPrim(int data)
{
	if(data<2) return false;
	int k=(int)sqrt(data);
	for(int i=2;i<=k;i++)
	{
		if(data%i == 0)
			return false;
	}
	return true;
}

int getTSize(int data)
{
	while(!isPrim(data)) ++data;
	return data;  
}

int getPosition(int data)
{
	for(int i=0;i<TSize;i++)
	{
		int k=(data+i*i)%TSize;
		if(Isfilled[k]==0)
		{
			Isfilled[k]=1;
			position[data]=k;
			break;
		}
	}
	return position[data];
}
int main()
{
	int n,m,data,res;
	cin>>n>>m;
	TSize = getTSize(n);
	cin>>data;
	res=getPosition(data);
	if(res == -1)
		cout<<"-";
	else cout<<res;
	
	for(int i=1;i<m;i++)
	{
		cin>>data;
		res = getPosition(data);
		if(res == -1)
			cout<<" -";
		else cout<<" "<<res;
	}
	return 0;
}
