#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int window[101];
struct cus
{
    int arrayTime;
    int serveTime;
};
cus Cus[10001];

bool cmp1(cus a,cus b)
{
    return a.arrayTime<b.arrayTime;
}

bool cmp2(int a,int b)
{
    return a<b;
}

int main()
{
    int N,K;
    cin>>N>>K;
    int hh,mm,ss,wait;
    for(int k=0;k<K;k++)
		window[k]=3600*8;
    int a=0,i=0;
    while(a<N)
    {
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&wait);
        if(hh*3600+mm*60+ss<17*3600+1)
        {
            Cus[i].arrayTime=hh*3600+mm*60+ss;
            Cus[i].serveTime=wait*60;
            i++;
        }
        a++;
    }
    sort(&Cus[0],&Cus[i],cmp1);
    int count=0;
    double total=0;
    for(int j=0;j<i;j++)
    {
        sort(&window[0],&window[K],cmp2);
        if(window[0]>Cus[j].arrayTime)
        {
            total+=(window[0]-Cus[j].arrayTime);
            window[0]+=Cus[j].serveTime;
        }
        else
        {
            window[0]=Cus[j].serveTime+Cus[j].arrayTime;
        }
        count++;
    }
    if(count>0)
		printf("%.1lf\n",(total/60)/count);
    else cout<<"0.0"<<endl;
    return 0;
}

