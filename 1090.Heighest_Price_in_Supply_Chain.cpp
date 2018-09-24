/*
1090 Highest Price in Supply Chain 
A supply chain is a network of retailers, distributors, and suppliers-- everyone involved 
in moving a product from supplier to customer.
Starting from one root supplier, everyone on the chain buys products from one's supplier 
in a price P and sell or distribute them in a price that is r% higher than P. It is assumed 
that each member in the supply chain has exactly one supplier except the root supplier, 
and there is no supply cycle.
Now given a supply chain, you are supposed to tell the highest price we can expect from 
some retailers.
Input Specification:
Each input file contains one test case. For each case, The first line contains three positive 
numbers: N (¡Ü10^5), the total number of the members in the supply chain (and hence they are 
numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate 
of price increment for each distributor or retailer. Then the next line contains N numbers, 
each number Si is the index of the supplier for the i-th member. Sroot for the root supplier 
is defined to be -1. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the highest price we can expect from some retailers, 
accurate up to 2 decimal places, and the number of retailers that sell at the highest price. 
There must be one space between the two numbers. It is guaranteed that the price will not exceed 10^10.

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<memory.h>
using namespace std;
const int MAX=100005;
int book[MAX];
vector<int> adj[MAX];
int maxlayer=0;

void dfs(int root, int depth)
{
//	cout<<root<<" "<<depth<<endl;
	if(adj[root].size()==0){
		book[root]=depth;
		if(depth > maxlayer) maxlayer=depth;
		return ;
	}
	for(int i=0;i<adj[root].size();i++)
		dfs(adj[root][i],depth+1);
}

int main()
{
	int N,root,data;
	double P,r;
	cin>>N>>P>>r;
	for(int i=0;i<N;i++)
	{
		cin>>data;
		if(data==-1) root=i;
		else adj[data].push_back(i);	
	}
	dfs(root,0);
	int cnt=0;
	for(int i=0;i<N;i++){
		if(book[i]==maxlayer)
			cnt++;
	}
	double result=pow((1+r/100),maxlayer)*P;
	printf("%.2lf %d\n",result,cnt);
	return 0;
}
