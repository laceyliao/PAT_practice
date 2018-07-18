#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAX=10002;
int N,M;
map<int,int> exist;
struct treenode{
	int val,l,r;
};
vector<treenode> tree(MAX);
void buildtree(int root,int id)
{
	if(tree[id].val < tree[root].val)
	{
		if(tree[root].l==-1) tree[root].l = id;
		else buildtree(tree[root].l,id);
	}
	else {
		if(tree[root].r==-1) tree[root].r = id;
		else buildtree(tree[root].r,id);
	}
}

int main()
{
	cin>>M>>N;
	int data;
	cin>>data;
	tree[0].val = data;
	tree[0].l = tree[0].r = -1;
	exist[data]=1;
	for(int i=1;i<N;i++)
	{
		cin>>data;
		exist[data]=1;
		tree[i].val = data;
		tree[i].l = tree[i].r = -1;
		buildtree(0,i);
	}
	int x,y,root;
	while(M--)
	{
		cin>>x>>y;
		if(!exist[x] && !exist[y])
			printf("ERROR: %d and %d are not found.\n",x,y);
		else if(!exist[x])
			printf("ERROR: %d is not found.\n",x);
		else if(!exist[y])
			printf("ERROR: %d is not found.\n",y);
		else {
			root = 0;
			while(true)
			{
				if(max(x,y) < tree[root].val) 
					root = tree[root].l;
				else if(min(x,y) > tree[root].val) 
					root = tree[root].r;
				else break;
			}
			if(x == tree[root].val) 
				printf("%d is an ancestor of %d.\n",x,y);
			else if(y == tree[root].val)
				printf("%d is an ancestor of %d.\n",y,x);
			else 
				printf("LCA of %d and %d is %d.\n",x,y,tree[root].val);
		}
	}
	return 0;
}
