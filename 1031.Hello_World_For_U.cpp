#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	int N,length,width;
	cin>>input;
	N = input.size()+2;
	int yu = N%3;
	if(yu == 0) {
		length=N/3;
		width = N/3;
	}
	else {
		length = N/3;
		width = N/3+yu;
	}
	int j = input.size()-1;
	int i = 0;
	for( ;i<length-1;i++,j--)	
	{
		cout<<input[i];
		for(int x=0; x<width-2 ;x++)
			cout<<" ";
		cout<<input[j];
		cout<<endl;
	}
	for(;i<width+length-1;i++)
		cout<<input[i];
		
	return 0;
}
