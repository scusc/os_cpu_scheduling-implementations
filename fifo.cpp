#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter no. of processes";
	cin>>n;
	int tlt,a[n],awt,att,c[n+1],d[n];
	char b[n][30];
	cout<<"enter process names";
	for (int i=0;i<n;i++)
	{
	cin>>b[i];
    }
    cout<<"enter the burst times";
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		c[i]=tlt;
		tlt=tlt+a[i];
		d[i]=tlt;
	}
	cout<<"PROCESS NAME\t\t BURST TIME\t\t WAITING TIME\t\t TURNARROUND TIME\n";
	cout<<"_________________________________________________________________________________________\n";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"\t\t\t"<<a[i]<<"ms"<<"\t\t\t"<<c[i]<<"ms"<<"\t\t\t\t"<<d[i]<<"ms\n";
	}
    cout<<" 'GANT CHART' of processes is\n";
    cout<<"_____________________________________________________\n";
    for(int i=0;i<n;i++)
    {
    	cout<<"   "<<b[i]<<"  "<<"|";
	}
	cout<<"\n___________________________________________________";
	cout<<"\n"<<"0";
	for(int i=0;i<n;i++)
    {
    	cout<<"      "<<d[i];
	}
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		sum1=sum1+c[i];
		sum2=sum2+d[i];
	}
	awt=sum1/n;
	att=sum2/n;
	cout<<"\navg waiting time is   "<<awt<<"ms\n";
	cout<<"avg  turnarround time is   "<<att<<"ms";
}
