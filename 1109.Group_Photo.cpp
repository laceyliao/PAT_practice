#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct people{
	string name;
	int height;
};

bool cmp(const people &p1,const people &p2)
{
	if(p1.height!=p2.height) return p1.height > p2.height;
	else return p1.name < p2.name;
}

int N,R;
int main()
{
	cin>>N>>R;
	int m=N/R;
	int last = m+N%R;
	vector<people> ps(N);
	for(int i=0;i<N;i++)
	{
		cin>>ps[i].name>>ps[i].height;
	}
	sort(ps.begin(),ps.end(),cmp);
	int idx=0;
	for(int i=0;i<R;i++)
	{
		int rowsize;
		if(i==0) rowsize=last;
		else rowsize=m;
		
		vector<string> row(rowsize);
		
		int mid=rowsize/2;
		row[mid]=ps[idx++].name;
		int l=mid-1,r=mid+1;
		while(l>=0 && r<rowsize)
		{
			row[l--]=ps[idx++].name;
			row[r++]=ps[idx++].name;
		}
		if(l==0) row[l]=ps[idx++].name;
		
		cout<<row[0];
		for(int j=1;j<row.size();j++)
		{
			cout<<" "<<row[j];
		}
		cout<<endl;
	}
	return 0;
}
