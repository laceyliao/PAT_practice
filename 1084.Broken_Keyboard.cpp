#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;

string input,output;
list<char> broken;
vector<bool> IsExisted(26,false);
vector<bool> IsIn(10,false);
int main()
{
	cin>>input;
	cin>>output;
	int length = input.size();
	int x=0 ,y=0;
	for(;x<length;x++,y++)
	{
		if(input[x] != output[y])
		{
			y--;
			if( input[x] >='0' && input[x] <= '9')
			{
				if(IsIn[input[x]-'0']==false)
				{
					broken.push_back(input[x]);
					IsIn[input[x]-'0'] = true;
				}
			}
			else {
				if(input[x] >= 'a' && input[x] <= 'z')
				{
					if( IsExisted[ input[x] - 'a'] == false)
					{
						broken.push_back(input[x]-'a'+'A');
						IsExisted[ input[x] - 'a'] = true; 
					}
				}
				else {
					if( IsExisted[ input[x] - 'A'] == false)
					{
						broken.push_back(input[x]);
						IsExisted[ input[x] - 'A'] = true; 
					}
				}
			}
		}
	}
	list<char>::iterator it=broken.begin();
	for(; it != broken.end(); it++)
	{
		cout<<*it;
	}
	return 0;
}
