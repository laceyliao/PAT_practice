/*
1133. Splitting A Linked List (25)

Given a singly linked list, you are supposed to rearrange its elements so that all the negative values 
appear before all of the non-negatives, and all the values in [0, K] appear before all those greater 
than K. The order of the elements inside each class must not be changed. For example, given the list 
being 18¡ú7¡ú-4¡ú0¡ú5¡ú-6¡ú10¡ú11¡ú-2 and K being 10, you must output -4¡ú-6¡ú-2¡ú7¡ú0¡ú5¡ú10¡ú18¡ú11.
Input Specification: 
Each input file contains one test case. For each case, the first line contains the address of the first node,
 a positive N (<= 105) which is the total number of nodes, and a positive K (<=1000). The address of a node
  is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer in [-105, 105], and Next is the position of 
the next node. It is guaranteed that the list is not empty.
Output Specification: 
For each case, output in order (from beginning to the end of the list) the resulting linked list. Each 
node occupies a line, and is printed in the same format as in the input. 

Sample Input:
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218

Sample Output:
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
*/
#include<iostream>
#include<string>
#include<list>
using namespace std;

const int MAX=100000;
int start,N,K;

struct point{
	int address;
	int data;
	int next;
};

point p[MAX];
list<point> mylist;

int main()
{
	int data;
	cin>>start>>N>>K;
	int begin,next;
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d",&begin,&data,&next);
		p[begin].address=begin;
		p[begin].data=data;
		p[begin].next=next;
	}
	begin = start;
	while(start!=-1)
	{
		data = p[start].data;
		if(data<0)
		{
			mylist.push_back(p[start]);
		}
		start = p[start].next;
	} 
	start = begin;
	while(start!=-1)
	{
		data = p[start].data;
		if(data>=0 && data<=K)
		{
			mylist.push_back(p[start]);
		}
		start = p[start].next;
	}
	start = begin;
	while(start!=-1)
	{
		data = p[start].data;
		if(data>K)
		{
			mylist.push_back(p[start]);
		}
		start = p[start].next;
	}
	
	point tmp;
	tmp = mylist.front();
	mylist.pop_front();
	printf("%05d %d ",tmp.address,tmp.data);
	
	while(!mylist.empty())
	{
		tmp = mylist.front();
		mylist.pop_front();
		printf("%05d\n",tmp.address);
		printf("%05d %d ",tmp.address,tmp.data);
	}	
	cout<<"-1"<<endl;
	
	return 0;
}
