/*
1006. Sign In and Sign Out (25)

CHEN, Yue
At the beginning of every day, the first person who signs in the computer room will 
unlock the door, and the last one who signs out will lock the door. Given the records 
of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day. 

Input Specification: 
Each input file contains one test case. Each case contains the records for one day. 
The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:
ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters. 

Output Specification: 
For each test case, output in one line the ID numbers of the persons who have unlocked and 
locked the door on that day. The two ID numbers must be separated by one space.
Note: It is guaranteed that the records are consistent. That is, the sign in time must be 
earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

Sample Input:
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:
SC3021234 CS301133
*/
#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

class worker{
	public:
		string ID,sign_in,sign_out;
		int start,end;
		
		worker(string a,string b,string c):ID(a),sign_in(b),sign_out(c) {
			int tmp=0;
			for(int i=0;i<b.size();i++)
			{
				if(b[i]!=':')
					tmp = tmp*10 + b[i] - '0';
			}
			start = tmp;
			tmp = 0;
			for(int i=0;i<c.size();i++)
			{
				if(c[i]!=':')
					tmp = tmp*10 + c[i] - '0';
			}
			end = tmp;
		}
		
		bool operator <(worker & w1)
		{
			if(start < w1.start) 
				return true;
			else return false;	
		} 
		
		worker &  operator *(){
			return *this;
		}
		
		void operator ++() {}
};

bool comparator_1(worker w1, worker w2)
{
	if(w1.end > w2.end) 
		return true;
	else return false;
}

int main()
{
	int M;
	string a,b,c;
	cin>>M;
	list<worker> unlock,lock;
	for(int i=0;i<M ;i++)
	{
		cin>>a>>b>>c;
		unlock.push_back(worker(a,b,c));
		lock.push_back(worker(a,b,c));
	}
	unlock.sort();
	lock.sort(comparator_1);
	list<worker>::iterator start=unlock.begin();
	list<worker>::iterator end = lock.begin();
	cout<<start->ID<<" "<<end->ID<<endl;

	return 0;
}
