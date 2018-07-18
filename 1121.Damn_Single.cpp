/*
1121. Damn Single (25)

CHEN, Yue
"Damn Single (µ•…Ìπ∑)" is the Chinese nickname for someone who is being single. You are supposed 
to find those who are alone in a big party, so they can be taken care of.
Input Specification: 
Each input file contains one test case. For each case, the first line gives a positive integer 
N (<=50000), the total number of couples. Then N lines of the couples follow, each gives a couple 
of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is 
a positive integer M (<=10000) followed by M ID's of the party guests. The numbers are separated 
by spaces. It is guaranteed that nobody is having bigamous marriage (÷ÿªÈ) or dangling with more than one companion.
Output Specification: 
First print in a line the total number of lonely guests. Then in the next line, print their ID's 
in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra 
space at the end of the line. 

Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333

Sample Output:
5
10000 23333 44444 55555 88888
*/

#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;

vector<int> couple(100000,-1);
set<int> single;
vector<bool> IsSingle(100000,true);

int main()
{
	int N,M,p1,p2;	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>p1>>p2;
		couple[p1]=p2;
		couple[p2]=p1;
	}
	cin>>M;
	vector<int> guests(M);
	for(int i=0;i<M;i++)
	{
		cin>>p1;
		guests[i]=p1;
		if(couple[guests[i]] != -1)
			IsSingle[couple[ guests[i] ] ]=false;
	}
	for(int i=0;i<M;i++)
	{
		if(IsSingle[ guests[i] ]) 
			single.insert(guests[i]);
	}
	cout<<single.size()<<endl;
	set<int>::iterator it=single.begin();
	for(;it != single.end();it++)
	{
		if(it!=single.begin()) cout<<" ";
		printf("%05d",*it);
	}
	return 0;
}

