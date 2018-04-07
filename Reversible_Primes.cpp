#include<iostream>
#include<string>

using namespace std;

bool IsPrime(int data)
{
	if(data < 2) return false;
	if(data==2 || data==3)
		return true;
	for(int i=2; i*i <= data; i++)
	{
		if(data%i == 0) return false;
	}
	return true;
}

int reverse_num(int N,int radix)
{
	int reversed=0;
	while(N>0)
	{
		reversed *= radix;
		reversed += N%radix;
		N /= radix;
	}
	return reversed;
}
int main()
{
	int N,radix,reversed;
	cin>>N;
	while(N>=0) {
		cin>>radix;
		reversed = reverse_num(N,radix);
		if( IsPrime(N) && IsPrime(reversed))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		cin>>N;
	}
	return 0;
}
