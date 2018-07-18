#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,P;

int main()
{
	cin>>N>>P;
	vector<long> data(N);
	
	for(int i=0;i<N;i++)
		cin>>data[i];
	
	sort(data.begin(),data.end());
	int max=0, lower=1;
	for(int i=0;i<N;i++)
	{
		long tmp = P*data[i];
		if(data[N-1] <= tmp)
		{
			if(N-i > max)
				max = N-i;
			break;
		}
		
		int upper = N-1;
		while(lower < upper)
		{
			int mid = (upper+lower)/2;
			if(data[mid] > tmp)
				upper = mid;
			else if(data[mid] < tmp)
				lower = mid+1;
			else {
				lower = mid+1;
				break;
			}
		}
		if(lower-i > max)
			max = lower-i;
	}
	
	cout<<max<<endl;
	return 0;
}

