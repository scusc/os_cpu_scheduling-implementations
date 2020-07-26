#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter no. of processes";
	cin>>n;
	int y,z,tlt,a[n],awt,att,c[n+1],d[n],pt[n],t,sum1=0,sum2=0;
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
	cout<<"enter priorities";
	for(int i=0;i<n;i++)
    {
    	cin>>pt[i];
	}
	for(int i=0;i<n;i++)
	{
				for(int j=i+1;j<n;j++)
				{
					if(pt[j]<pt[i])
					{
						y=pt[i];
						pt[i]=pt[j];
						pt[j]=y;
						
						t=a[j];
						a[j]=a[i];
						a[j]=t;
					}
			    }
    } 
    for(int i=0;i<n;i++)
    {
    	if(i==0)
    	{
    	c[i]=0;
    	d[i]=a[i];
        }
        else
        {
        	c[i]=a[i-1]+c[i-1];
        	d[i]=a[i]+c[i];
        	sum1=sum1+c[i];
	    	sum2=sum2+d[i];
		}
	}
    awt=sum1/n;
	att=sum2/n;
	cout<<"PROCESS NAME\t\t BURST TIME\t\t WAITING TIME\t\t TURNARROUND TIME\tPRIORITIES";
	cout<<"___________________________________________________________________________________________________________________\n";
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<"\t\t\t"<<a[i]<<"ms"<<"\t\t\t"<<c[i]<<"ms"<<"\t\t\t\t"<<d[i]<<"ms\t\t\t"<<pt[i]<<"\n";
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
