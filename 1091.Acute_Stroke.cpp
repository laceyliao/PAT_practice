/*
1091 Acute Stroke 
One important factor to identify acute stroke is the volume of the stroke core. Given the results 
of image analysis in which the core regions are identified in each MRI slice, your job is to calculate 
the volume of the stroke core.
Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: 
M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M¡ÁN matrix, 
and the maximum resolution is 1286 by 128); L (¡Ü60) is the number of slices of a brain; and T is the 
integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).
Then L slices are given. Each slice is represented by an M¡ÁN matrix of 0's and 1's, where 1 represents 
a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to 
count the number of 1's to obtain the volume. However, there might be several separated core regions 
in a brain, and only those with their volumes no less than T are counted. Two pixels are connected and 
hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red 
pixels are connected to the blue one.

Output Specification:
For each case, output in a line the total volume of the stroke core.
Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/
#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

struct node{
	int x,y,z;
};

int pixel[1290][130][61];
bool inq[1290][130][61];
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
int M,N,L,T;

bool judge(int x,int y,int z){
	if(x>=M || x<0 ||y>=N || y<0 || z>=L || z<0) 
		return false;
	if(pixel[x][y][z]==0 || inq[x][y][z]) 
		return false;
	return true;
}
int bfs(int x,int y,int z)
{
	int tot=0;
	queue<node> q;
	node Node;
	Node.x=x;
	Node.y=y;
	Node.z=z;
	q.push(Node);
	inq[x][y][z]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++)
		{
			int newx=top.x+X[i];
			int newy=top.y+Y[i];
			int newz=top.z+Z[i];
			if(judge(newx,newy,newz)){
				Node.x = newx;
				Node.y = newy;
				Node.z = newz;
				q.push(Node);
				inq[newx][newy][newz] = true;
			}
		}
	}
	if(tot>=T) return tot;
	else return 0;
}
int main()
{
	memset(inq,false,sizeof(inq));
	cin>>M>>N>>L>>T;
	for(int i=0;i<L;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++)
				cin>>pixel[j][k][i];
	int ans=0;
	for(int i=0;i<L;i++)
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++)
			{
				if(pixel[j][k][i]==1 && !inq[j][k][i]){
					ans+=bfs(j,k,i);
				}		
			}
	cout<<ans<<endl;
	return 0;
}
