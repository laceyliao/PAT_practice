#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
	string input;
	cin>>input;
	int count = 0;
	for(int i=0;i<input.size();i++)
	{
		count += input[i]-'0';
	}
	list<int>  data;
	while(count>0)
	{
		data.push_front(count%10);
		count = count/10;
	}
	list<int>::iterator it=data.begin();
	switch(*it){
			case 0:
				cout<<"zero";
				break;
			case 1:
				cout<<"one";
				break;
			case 2:
				cout<<"two";
				break;
			case 3:
				cout<<"three";
				break;
			case 4:
				cout<<"four";
				break;
			case 5:
				cout<<"five";
				break;
			case 6:
				cout<<"six";
				break;
			case 7:
				cout<<"seven";
				break;
			case 8:
				cout<<"eight";
				break;
			case 9:
				cout<<"nine";
				break;	 
	}
	
	it++;
	
	for(; it!=data.end(); it++)
	{
		switch(*it){
			case 0:
				cout<<" zero";
				break;
			case 1:
				cout<<" one";
				break;
			case 2:
				cout<<" two";
				break;
			case 3:
				cout<<" three";
				break;
			case 4:
				cout<<" four";
				break;
			case 5:
				cout<<" five";
				break;
			case 6:
				cout<<" six";
				break;
			case 7:
				cout<<" seven";
				break;
			case 8:
				cout<<" eight";
				break;
			case 9:
				cout<<" nine";
				break;	 
		}
	}
	return 0;
}
