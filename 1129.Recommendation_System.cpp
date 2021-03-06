/*
1129 Recommendation System (25)��25 �֣�
Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a 
very simple recommendation system that rates the user's preference by the number of times that an item has 
been accessed by this user.
Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers: 
N (<= 50000), the total number of queries, and K (<= 10), the maximum number of recommendations the system 
must show to the user. Then given in the second line are the indices of items that the user is accessing -- 
for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.
Output Specification:
For each case, process the queries one by one. Output the recommendations for each query in a line in the format:
query: rec[1] rec[2] ... rec[K]
where query is the item that the user is accessing, and rec[i] (i = 1, ... K) is the i-th item that the system 
recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended 
in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.
Note: there is no output for the first item since it is impossible to give any recommendation at the time. 
It is guaranteed to have the output for at least one query.
Sample Input:
12 3
3 5 7 5 5 3 2 1 8 3 8 12
Sample Output:
5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8
*/
#include<iostream>
#include<set>
#include<memory.h>
using namespace std;
const int MAX=50002;
int totaltimes[MAX];
struct data{
	int id,times;
	data(int i,int t):id(i),times(t){}
	bool operator < (const data &a) const{
		if(times == a.times) return id<a.id;
		else return times > a.times;
	}
};

int main()
{
	int N,K,query;
	memset(totaltimes,0,sizeof(totaltimes));
	scanf("%d %d",&N,&K);
	scanf("%d",&query);
	set<data> d;
	totaltimes[query]++;
	d.insert(data(query,totaltimes[query]));
	for(int i=1;i<N;i++)
	{
		scanf("%d",&query);
		printf("%d:",query);
		set<data>::iterator it=d.begin();
		for(int j=0;j<K && it!=d.end();j++,it++)
		{
			printf(" %d",it->id);
		}
		printf("\n");
		it=d.find(data(query,totaltimes[query]));
		totaltimes[query]++;
		if(it!=d.end()) {
			d.erase(it);
		}
		d.insert(data(query,totaltimes[query]));
	}
	return 0;
}
