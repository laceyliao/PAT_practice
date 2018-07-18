#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

struct data{
	string name;
	int tws;
	double ttws;
	int cnt;
	int rank;
	data(){
		ttws=0.0;
		tws=0;
		cnt=0;
		rank=0;
	}
};
map<string,data>  input;
vector<data> result;

bool cmp(data a,data b)
{
	if(a.tws!=b.tws) return a.tws > b.tws;
	else if(a.cnt!=b.cnt) return a.cnt<b.cnt;
	else return a.name < b.name;
}
int main()
{
	int N;
	string ID,school;
	double score;
	
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>ID;
		scanf("%lf",&score);
		cin>>school;
	//	scanf("%s %lf %s",&ID,&score,&school);
		int leg=school.length();
		for(int j=0;j<leg;j++)
		{
			if(school[j]>='A' && school[j]<='Z')
				school[j]='a'+school[j]-'A';
		}
		if(ID[0]=='T') {
			input[school].ttws += score*1.5;
		}
		else if(ID[0]=='A') {
			input[school].ttws += score;
		}
		else {
			input[school].ttws += score/1.5;
		}
		input[school].cnt++;
	}	
	map<string,data>::iterator it=input.begin();
	for(;it!=input.end();it++)
	{
		data tmp=it->second;
		tmp.tws = (int)tmp.ttws;
		tmp.name = it->first;
		result.push_back(tmp);
	}
	sort(result.begin(),result.end(),cmp);
	int r=1,grade=0;
	int size = result.size();
	cout<<size<<endl;
	result[0].rank=r;
	for(int i=0;i<size;i++)
	{
		if(result[i].tws == grade)
		{
			result[i].rank = r;
		}
		else {
			r = 1+i;
			result[i].rank=r; 
			grade = result[i].tws;
		}
		printf("%d %s %d %d\n",result[i].rank,result[i].name.c_str(),result[i].tws,result[i].cnt);
	} 
	return 0;
}
