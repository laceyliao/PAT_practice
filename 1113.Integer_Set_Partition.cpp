#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N,tmp,sum=0,halfsum=0;
	cin>>N;
	vector<int> data(N);
	
	for(int i=0;i<N;i++)
	{
		cin>>tmp;
		data[i]=tmp;
		sum+=tmp;
	}
	sort(data.begin(),data.end());

	for(int i=0;i<N/2;i++)
	{
		halfsum+=data[i];
	}
	cout<<N%2<<" "<<sum-2*halfsum<<endl;
	return 0;
}
