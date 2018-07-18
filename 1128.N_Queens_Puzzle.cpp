/*
1128 N Queens Puzzle (20)£¨20 ·Ö£©
The "eight queens puzzle" is the problem of placing eight chess queens on an 8¡Á8 chessboard 
so that no two queens threaten each other. Thus, a solution requires that no two queens share 
the same row, column, or diagonal. The eight queens puzzle is an example of the more general 
N queens problem of placing N non-attacking queens on an N¡ÁN chessboard. (From Wikipedia - "Eight queens puzzle".)
Here you are NOT asked to solve the puzzles. Instead, you are supposed to judge whether or not 
a given configuration of the chessboard is a solution. To simplify the representation of a chessboard, 
let us assume that no two queens will be placed in the same column. Then a configuration can be 
represented by a simple integer sequence (Q~1~, Q~2~, ..., Q~N~), where Q~i~ is the row number 
of the queen in the i-th column. For example, Figure 1 can be represented by (4, 6, 8, 2, 7, 1, 3, 5) 
and it is indeed a solution to the 8 queens puzzle; while Figure 2 can be represented by 
(4, 6, 7, 2, 8, 1, 9, 5, 3) and is NOT a 9 queens' solution.

  Figure 1 Figure 2

Input Specification:
Each input file contains several test cases. The first line gives an integer K (1 < K <= 200). 
Then K lines follow, each gives a configuration in the format "N Q~1~ Q~2~ ... Q~N~", where 4 <= N <= 1000 
and it is guaranteed that 1 <= Q~i~ <= N for all i=1, ..., N. The numbers are separated by spaces.
Output Specification:
For each configuration, if it is a solution to the N queens problem, print "YES" in a line; or "NO" if not.
Sample Input:
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
Sample Output:
YES
NO
NO
YES
*/
#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX=1002;
int queen[MAX][MAX];
bool isfill[MAX];
int main()
{
	int K,N,Q;
	scanf("%d",&K);
	while(K--)
	{
		memset(queen,0,sizeof(queen));
		memset(isfill,false,sizeof(isfill));
		bool flag=false;
		scanf("%d",&N);
		
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&Q);
			if(!flag && isfill[Q]==false && queen[Q][i]==0 )
			{
				isfill[Q]=true;
				int j=Q,z=i;
				for( ;j>=1 && j<=N && z>=1 && z<=N; j--,z-- ){
					queen[j][z]=Q;
				}

				j=Q,z=i;
				for( ;j>=1 && j<=N && z>=1 && z<=N; j--,z++ ){
					queen[j][z]=Q;
				}
					
				j=Q,z=i;
				for( ;j>=1 && j<=N && z>=1 && z<=N; j++,z++ ){
					queen[j][z]=Q;
				}
					
				j=Q,z=i;
				for( ;j>=1 && j<=N && z>=1 && z<=N; j++,z-- ){
					queen[j][z]=Q;
				}
					
			}
			else flag=true;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
 } 
