#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int TSize;
const int MAX=100010;
vector<bool>  IsFilled(MAX,false);
vector<int> Step(MAX,0);

bool IsPrim(int data)
{
	if(data<2) return false;
	int k = int( sqrt(data) );
	for(int i=2;i<=k;i++)
	{
		if(data%i==0) return false;
	}
	return true;
}
int GetTSize(int MS)
{
	while(!IsPrim(MS)) MS++;
	return MS;
}

bool InsertElem(int data)
{
	int step=1;
	for(int i=0; i <TSize; i++)
	{
		int key = (data + i*i )%TSize;
		if(IsFilled[key] == false)
		{
			IsFilled[key] = true;
			break;
		}
		step++;
	}
	Step[data]=step; 
	return step > TSize ? false : true;
}

int GetStep(int data)
{
	if(Step[data]!=0) return Step[data];
	else {
		int step=1;
		for(int i=0; i <TSize; i++)
		{
			int key = (data + i*i )%TSize;
			if(IsFilled[key] == false)
			{
				return step;
			}
			step++;
		}
		return step;
	}
}

int main()
{
	int MSize,N,M,data;
	cin>>MSize>>N>>M;
	TSize=GetTSize(MSize);
	cout<<TSize<<endl;
	for(int i=0;i<N;i++)
	{
		cin>>data;
		if( !InsertElem(data) ) 
			cout<<data<<" cannot be inserted."<<endl;
	}
	double sum=0.0;
	for(int i=0;i<M;i++)
	{
		cin>>data;
		sum += GetStep(data);
	}
	
	printf("%.1f\n",sum/M);
	return 0;
}
