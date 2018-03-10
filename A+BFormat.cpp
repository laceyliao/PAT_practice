/*
1001. A+B Format (20)

CHEN, Yue
Calculate a + b and output the sum in standard format -- that is, the digits must be 
separated into groups of three by commas (unless there are less than four digits).
Input
Each input file contains one test case. Each case contains a pair of integers a and b 
where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum must be
 written in the standard format. 
 
Sample Input
-1000000 9

Sample Output
-999,991
*/
#include<iostream>
using namespace std;

int main()
{
	int a,b,result,negative = 1;
	cin>>a>>b;
	result = a+b;
	if(result < 0) {
		negative = -1;
		result = -1*result;
	}
		
	if(result/1000 > 0){
		int aud[10] = {0};
		for(int i=0;i<3;i++)
		{
			aud[i]=result%10;
			result /= 10;
		}
		if(result/1000 > 0) {
			for(int i=3;i<6;i++)
			{
				aud[i]=result%10;
				result /= 10;
			}
			cout<<negative*result<<",";
			for(int i=5;i>=3;i--)
				cout<<aud[i];
			cout<<",";
			for(int i=2;i>=0;i--)
				cout<<aud[i];
			cout<<endl;
		}
		else { 
			cout<<negative*result<<",";
			for(int i=2;i>=0;i--)
				cout<<aud[i];
			cout<<endl;
		} 
	}
	else cout<<negative*result<<endl;
	return 0;	
} 
