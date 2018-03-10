/*
1002. A+B for Polynomials (25)

CHEN, Yue
This time, you are supposed to find A+B where A and B are two polynomials.
Input
Each input file contains one test case. Each case occupies 2 lines, and each 
line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) 
are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000. 

Output
For each test case you should output the sum of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place. 

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 2 1.5 1 2.9 0 3.2
*/
#include<iostream>
#include<map>
#include<iomanip>
#include<algorithm>
using namespace std;

typedef map<int,float> poly;

int Compare(int a,int b)
{
	if(a>b) return -1;
	else if (a<b) return 1;
	else return 0;
}

void Attach(int expo,float coef, poly &obj)
{
	obj.insert(make_pair(expo,coef));
}

void Printer(pair<int,float> p)
{
	cout<<" "<< (p.first)*(-1) <<" "<< p.second;
}

int main(){
	int K,expo;
	float coef;
	poly A,B,C;
	cin>>K;
	for(int i=0;i<K;i++)
	{
		cin>>expo>>coef;
		A[-expo] = coef;
	}
	cin>>K;
	for(int i=0;i<K;i++)
	{
		cin>>expo>>coef;
		B[-expo] = coef;
	}
	
	poly::iterator pA = A.begin();
	poly::iterator pB = B.begin();
	
	float sum=0.0;

	while(pA!=A.end() && pB!=B.end() ){
		switch (Compare(pA->first, pB->first)){
			case 1:
				Attach(pA->first,pA->second,C);
				pA++;
				break;
			case -1:
				Attach(pB->first,pB->second,C);
				pB++;
				break;
			case 0:
				sum = pA->second + pB->second;
				if(sum != 0.0) Attach(pA->first,sum,C);
				pA++;
				pB++;
				break;
		}
	}

	for(;pA != A.end(); pA++)
		Attach(pA->first,pA->second,C);
	for(;pB != B.end(); pB++)
		Attach(pB->first,pB->second,C);
		
	cout<<C.size();
	cout<<setiosflags(ios::fixed)<<setprecision(1);
	for_each(C.begin(), C.end(), Printer);
	return 0;
}
