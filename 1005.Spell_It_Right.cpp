/*
Given a non-negative integer N, your task is to compute the sum of all the digits of N, 
and output every digit of the sum in English. 
Input Specification: 
Each input file contains one test case. Each case occupies one line which contains an N (<= 10100). 
Output Specification: 
For each test case, output in one line the digits of the sum in English words. There must be one 
space between two consecutive words, but no extra space at the end of a line. 

Sample Input:
12345

Sample Output:
one five
*/
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
