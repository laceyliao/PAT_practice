#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Palindromic(vector<int> &data,int times,int limit)
{
	if(times>=limit) {
		for(int z=0;z<data.size();z++)
			cout<<data[z];
		cout<<endl;
		cout<<limit;
		return;
	}
	int length = data.size();
	int i=0;
	for(;i<=length/2;i++)
	{
		if(data[i]!=data[length-1-i])
			break;
	}
	if(i==length/2+1)
	{
		for(int z=0;z<data.size();z++)
			cout<<data[z];
		cout<<endl;
		cout<<times;
		return;
	}
	else{
		vector<int> outcome;
		int tmp=0;
		int x=0,y=length-1;
		for(;x<length;x++,y--)
		{
			tmp+=data[y]+data[x];
			outcome.push_back(tmp%10);
			tmp/=10;
		}
		if(tmp!=0) outcome.push_back(tmp);
		vector<int> newdata(outcome.size());
		x=0;
		y=outcome.size()-1;
		for(;y>=0;y--,x++)
		{
			newdata[x]=outcome[y];
		}
		Palindromic(newdata,times+1,limit);
	}
}
int main()
{
	int K;
	string input;
	cin>>input>>K;
	int length=input.size();
	vector<int>  data(length);
	for(int i=0;i<length;i++)
	{
		data[i] = input[i]-'0';
	}
	Palindromic(data,0,K);
	return 0;
}
