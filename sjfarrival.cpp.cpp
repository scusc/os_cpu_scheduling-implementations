#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter no. of processes";
	cin>>n;
	int tlt,a[n],awt,att,c[n+1],d[n],at[n];
	char b[n][30],y[n];
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
	cout<<"enter arrival times";
	for(int i=0;i<n;i++)
    {
    	cin>>at[i];
	}
	for (int i=1;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(a[j]<a[i])
    		{
    			int t=a[j];
    			strcpy(y,b[j]);
    			a[j]=a[i];
    			strcpy(b[j],b[i]);
    			a[i]=t;
    			strcpy(b[i],y);
    			int s=at[j];
    			at[j]=at[i];
    			at[i]=s;
			}
		}
	}
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
		c[i]=tlt+at[i];
		tlt=tlt+a[i]+at[i];
		d[i]=tlt;
		sum1=sum1+c[i];
		sum2=sum2+d[i];
	    }
	    else
	    {
	    c[i]=tlt;
		tlt=tlt+a[i];
		d[i]=tlt;
		sum1=sum1+c[i];
		sum2=sum2+d[i];
		}
	}
	awt=sum1/n;
	att=sum2/n;
	cout<<"PROCESS NAME\t\t BURST TIME\t\t ARRIVAL TIME\t\t WAITING TIME\t\t TURNARROUND TIME\n";
	cout<<"________________________________________________________________________________________________________________________\n";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"\t\t\t"<<a[i]<<"ms"<<"\t\t\t"<<at[i]<<"ms"<<"\t\t\t"<<c[i]<<"ms"<<"\t\t\t\t"<<d[i]<<"ms\n";
	}
    cout<<" 'GANT CHART' of processes is\n";
    cout<<"_____________________________________________________\n";
    for(int i=0;i<n;i++)
    {
    	cout<<"   "<<b[i]<<"  "<<"|";
	}
	cout<<"\n___________________________________________________";
	cout<<"\n"<<at[0];
	for(int i=0;i<n;i++)
    {
    	cout<<"      "<<d[i];
	}
	cout<<"\navg waiting time is   "<<awt<<"ms\n";
	cout<<"avg  turnarround time is   "<<att<<"ms";
}
