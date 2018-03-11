/*
1007. Maximum Subsequence Sum (25)

CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be 
{ Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence 
which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, 
its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence. 
Input Specification: 
Each input file contains one test case. Each case occupies two lines. The first line contains 
a positive integer K (<= 10000). The second line contains K numbers, separated by a space. 
Output Specification: 
For each test case, output in one line the largest sum, together with the first and the last 
numbers of the maximum subsequence. The numbers must be separated by one space, but there must 
be no extra space at the end of a line. In case that the maximum subsequence is not unique, 
output the one with the smallest indices i and j (as shown by the sample case). If all the 
K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to 
output the first and the last numbers of the whole sequence. 

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:
10 1 4
*/
#include<iostream>
using namespace std;

int main()
{
	int K, this_sum=0, max_sum=-1, begin, end;
//	bool change = false;
	int data[10002];
	cin>>K;
	for(int i=0;i<K;i++)
		cin>>data[i];
	
	begin = data[0];
	end = data[0];
	
	int x;
	x = data[0];
		
	for(int i=0;i<K;i++)
	{
		this_sum += data[i];
		if(this_sum < 0) {
			this_sum =0;
			x = data[i+1];
		}
		else{
			if(this_sum > max_sum) 
			{
				max_sum = this_sum;		
				begin = x;
				end = data[i];
			}	
		}
		
	}
	if(max_sum>-1) 
 		cout<<max_sum<<" "<<begin<<" "<<end<<endl;
 	else 
 		cout<<"0"<<" "<<data[0]<<" "<<data[K-1]<<endl;
	return 0;
}
