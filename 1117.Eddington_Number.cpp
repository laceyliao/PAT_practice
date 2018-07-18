#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	if(a>b) return true;
	else return false;
}
int main()
{
	int N,miles,count=1;
	cin>>N;
	vector<int>  dailyride(N);
	for(int i=0;i<N;i++)
	{
		cin>>miles;
		dailyride[i] = miles;
	}
	sort(dailyride.begin(),dailyride.end(),cmp);//big->small
	for(int x=0;x<N;x++,count++)
	{
		if(dailyride[x] <= count)
			break;
	}
	cout<<count-1<<endl;
	return 0;
}
