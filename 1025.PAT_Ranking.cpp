#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int INF=99999;

struct student{
	string id;
	int score,location,final_rank,local_rank;
	student() {}
	student(string a,int b,int c){
		id=a;
		score=b;
		location=c;
	}
	bool operator > (const student& s) const
	{
		if(score!=s.score)
			return score>s.score;
		else return id<s.id;
	}
};

vector<student> V;

int main()
{
	int N,K,score;
	string id;
	int grade = INF;
	int rank=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>K;
		vector<student> tmp;
		for(int j=0;j<K;j++)
		{
			cin>>id>>score;
			tmp.push_back(student(id,score,i+1));
		}
		sort(tmp.begin(), tmp.end(),greater<student>() );

		for(int j=0;j<K;j++)
		{
			if(tmp[j].score == grade)
			{
				tmp[j].local_rank = rank;
			}
			else
			{
				rank = j+1;
				tmp[j].local_rank = rank;
				grade = tmp[j].score;
			}
			V.push_back(tmp[j]);
		}
	}
	sort(V.begin(),V.end(),greater<student>());
	grade = INF;
	rank = 0;
	cout<<V.size()<<endl;
	for(int i=0;i<V.size();i++)
	{
		if(V[i].score == grade)
			V[i].final_rank = rank;
		else {
			rank = i+1;
			V[i].final_rank = rank;
			grade = V[i].score;
		}
		cout<<V[i].id<<" "<<V[i].final_rank<<" "<<V[i].location<<" "<<V[i].local_rank<<endl;
	}
	return 0;
}
