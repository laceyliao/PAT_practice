#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int D,N;
	cin>>D>>N;
	vector<int> res;
	res.push_back(D);
	for(int i=1;i<N;i++)
	{
		vector<int> v;
		int tmp=res[0];
		int cnt=1;
		for(int j=1;j<res.size();j++)
		{
			if(res[j]!=tmp)
			{
				v.push_back( tmp );
				v.push_back(cnt);
				cnt=1;
				tmp=res[j];
			}
			else cnt++;
		}
		v.push_back(tmp);
		v.push_back(cnt);
		res = v;
	}
	for(int i=0;i<res.size();i++)
		cout<<res[i];
	return 0;
}
