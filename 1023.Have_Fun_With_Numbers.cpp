#include<iostream>
#include<string> 
#include<vector>
#include<list>
using namespace std;

int main()
{
	string data;
	vector<int>  content(10,0);
	list<int>::iterator it;
	cin>>data;
	int length = data.size();
	for(int i=0;i<length;i++)
	{
		content[data[i]-'0']++;
	}
	list<int> ddata;
	int tmp=0;
	for(int i=length-1;i>=0;i--)
	{
		tmp += (data[i]-'0')*2;
		ddata.push_front(tmp%10);
		tmp /=10;
	}
	
	if(tmp!=0)
	{
		cout<<"No"<<endl;
		ddata.push_front(tmp);
	}
	else
	{
		vector<int> result(10,0);
		it=ddata.begin();
		for(;it!=ddata.end();it++)
		{
			result[*it]++;
		}
		int index;
		for(index=0;index<10;index++)
		{
			if(content[index]!=result[index])
			{
				cout<<"No"<<endl;
				break;
			}
		}
		if(index == 10)
			cout<<"Yes"<<endl;
	}
	it=ddata.begin();
	for(;it!=ddata.end();it++)
	{
		cout<<*it;
	}
	return 0;
}
