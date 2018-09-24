/*
1093 Count PAT's 
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, 
the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.
Now given any string, you are supposed to tell the number of PAT's contained in the string.
Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of no more 
than 10^5 characters containing only P, A, or T.
Output Specification:
For each test case, print in one line the number of PAT's contained in the string. 
Since the result may be a huge number, you only have to output the result moded by 1000000007.
Sample Input:
APPAPT
Sample Output:
2
*/
#include<iostream>
#include<string>
using namespace std;

const long long MAX=1000000007;

int main()
{
	string data;
	cin>>data;
	long long index=data.find_first_of('A');
	long long cntp=0,cntt=0,ans=0;
	for(int i=0;i<index;i++)
		if(data[i]=='P') cntp++;
	for(int i=index+1;i<data.length();i++)
		if(data[i]=='T') cntt++;
	for( ;index<data.length();index++)
	{
		if(data[index]=='A')
			ans = (ans + cntp*cntt)%MAX;
		else if(data[index]=='P')
			cntp++;
		else cntt--;	
	}
	cout<<ans<<endl;
	return 0;
}
