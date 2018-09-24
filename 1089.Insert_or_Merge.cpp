/*
1089 Insert or Merge 
According to Wikipedia:
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. 
Each iteration, insertion sort removes one element from the input data, finds the location it belongs 
within the sorted list, and inserts it there. It repeats until no input elements remain.
Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element 
(a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce 
new sorted sublists until there is only 1 sublist remaining.
Now given the initial sequence of integers, together with a sequence which is a result of several 
iterations of some sorting method, can you tell which sorting method we are using?
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer 
N (¡Ü100). Then in the next line, N integers are given as the initial sequence. The last line 
contains the partially sorted sequence of the N numbers. It is assumed that the target sequence 
is always ascending. All the numbers in a line are separated by a space.
Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate 
the method used to obtain the partial result. Then run this method for one more iteration and 
output in the second line the resuling sequence. It is guaranteed that the answer is unique for 
each test case. All the numbers in a line must be separated by a space, and there must be 
no extra space at the end of the line.

Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0

Sample Input 2:
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
Sample Output 2:
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX=102;
int input[MAX],orgin[MAX],aud[MAX];

bool Insertion_Sort(int n)
{
	bool flag=false;
	for(int index=1;index<n;index++)
	{
		int i=index;
		int tmp=aud[i];
		while(tmp<aud[i-1] && i>0)
		{
			aud[i]=aud[i-1];
			i--;
		}
		aud[i]=tmp;
		if(flag) break;
		if(memcmp(aud,input,sizeof(int)*n)==0) 	flag= true;
	}
	return flag;
}

void Merge_Sort(int n)
{
	bool flag=true;
	int k=1;
	while(flag)
	{
		flag=false;
		if(memcmp(aud,input,sizeof(int)*n)!=0) 	flag= true;
		k*=2;
		for(int i=0;i<n/k;i++)
			sort(aud+i*k,aud+(i+1)*k);
		sort(aud+(n/k)*k,aud+n);
	}
}

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>orgin[i];
	for(int i=0;i<N;i++)
		cin>>input[i];
	
	memcpy(aud,orgin,sizeof(int)*N);
	if(Insertion_Sort(N)){
		cout<<"Insertion Sort"<<endl;
	}
	else{
		cout<<"Merge Sort"<<endl;
		memcpy(aud,orgin,sizeof(int)*N);
		Merge_Sort(N);
	}
	for(int i=0;i<N-1;i++)
		cout<<aud[i]<<" ";
	cout<<aud[N-1]<<endl;
	return 0;
}
