/*
1088 Rational Arithmetic
For two rational numbers, your task is to implement the basic arithmetics, that is, 
to calculate their sum, difference, product and quotient.
Input Specification:
Each input file contains one test case, which gives in one line the two rational 
numbers in the format a1/b1 a2/b2. The numerators and the denominators are all in 
the range of long int. If there is a negative sign, it must appear only in front 
of the numerator. The denominators are guaranteed to be non-zero numbers.
Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of 
the two rational numbers, respectively. The format of each line is number1 operator 
number2 = result. Notice that all the rational numbers must be in their simplest 
form k a/b, where k is the integer part, and a/b is the simplest fraction part. 
If the number is negative, it must be included in a pair of parentheses. If the 
denominator in the division is zero, output Inf as the result. It is guaranteed 
that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
#include<iostream>
#include<cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	while(b>0)
	{
		long long tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
void normalize(long long numerator, long long denominator)
{
	int negative=0;
	if(denominator==0){
		cout<<"Inf";
		return ;
	}
	if(numerator==0){
		cout<<"0";
		return ;
	}
	if(numerator < 0) {
		negative++;
		numerator = -numerator;
	}
	if(denominator < 0){
		negative++;
		denominator = -denominator;
	}
	int mygcd = gcd(numerator,denominator);
	numerator/=mygcd;
	denominator/=mygcd;
	int tmp=numerator/denominator, tmp2=numerator%denominator;
	if(tmp==0){
		if(negative==1){
			cout<<"(-"<<numerator<<"/"<<denominator<<")";
		}
		else cout<<numerator<<"/"<<denominator;
	}
	else{
		if(negative==1){
			if(tmp2==0)	cout<<"(-"<<tmp<<")";
			else  cout<<"(-"<<tmp<<" "<<numerator-tmp*denominator<<"/"<<denominator<<")";
		}
		else {
			if(tmp2==0) cout<<tmp;
			else cout<<tmp<<" "<<numerator-tmp*denominator<<"/"<<denominator;
		}
	}
}

int main()
{
	long long a1,b1,a2,b2;
	char op1,op2;
	cin>>a1>>op1>>b1;
	cin>>a2>>op2>>b2;
	for(int i=1;i<=4;i++)
	{
		normalize(a1, b1);
		switch(i) {
			case 1:
				cout<<" + ";
				normalize(a2, b2);
				cout<<" = ";
				normalize(a1*b2+a2*b1,b1*b2);
				cout<<endl;
				break;
			case 2:
				cout<<" - ";
				normalize(a2, b2);
				cout<<" = ";
				normalize(a1*b2-a2*b1,b1*b2);
				cout<<endl;
				break;
			case 3:
				cout<<" * ";
				normalize(a2, b2);
				cout<<" = ";
				normalize(a1*a2,b1*b2);
				cout<<endl;
				break;
			case 4:
				cout<<" / ";
				normalize(a2, b2);
				cout<<" = ";
				normalize(a1*b2,b1*a2);
				cout<<endl;
				break;
		}
	}
	return 0;
 } 
