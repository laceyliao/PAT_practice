#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAX=100002;
vector<bool> input(MAX,false);

int main()
{
	int N,data;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&data);
		if(data>0 && data<MAX) {
			input[data]=true;
		}
	}
	for(int i=1;i<MAX;i++)
	{
		if(!input[i])
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
