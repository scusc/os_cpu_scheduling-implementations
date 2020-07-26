#include<iostream>
using namespace std;
int main()
{
	int i,j,c,n,e,t1=0,t2=0;
	float a1=0.00,a2=0.00;
	cout<<"Enter Number Of Process : ";
	cin>>n;
	int bt[n],p[n],wt[n],tat[n],pr[n];
	for(i=0;i<n;i++)
	{
		cout<<"enter process names p";
		cin>>p[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<"Enter Burst Time Of Process p"<<i+1<<":";
				cin>>bt[i];
				p[i]=i;
		cout<<"Enter Priorty Of Process p"<<i+1<<":";
				cin>>pr[i];
	}
	for(i=0;i<n;i++)
	{
				for(j=i+1;j<n;j++)
				{
					if(pr[j]<pr[i])
					{
						c=pr[i];
						pr[i]=pr[j];
						pr[j]=c;
						
						c=bt[j];
						bt[j]=bt[i];
						bt[i]=c;
						
						e=p[i];
						p[i]=p[j];
						p[j]=e;
					}
				}
				
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			wt[i]=0;
			tat[i]=bt[i];
		}
		else
		{
			wt[i]=wt[i-1]+bt[i-1];
			tat[i]=bt[i]+wt[i];
		}
		t1=t1+wt[i];
		t2=t2+tat[i];
	}
	a1=t1/n;
	a2=t2/n;
	cout<<"PROCESS NAME\t\t BURST TIME\t\t WAITING TIME\t\t TURNARROUND TIME\t\tPRIORITIES";
	cout<<"_______________________________________________________________\n";
	for(int i=0;i<n;i++)
	{
		cout<<"p"<<p[i]<<"\t\t\t"<<bt[i]<<"ms"<<"\t\t\t"<<wt[i]<<"ms"<<"\t\t\t\t"<<tat[i]<<"ms\t\t"<<pr[i]<<"\n";
	}
    cout<<" 'GANT CHART' of processes is\n";
    cout<<"_____________________________________________________\n";
    for(int i=0;i<n;i++)
    {
    	cout<<"   p"<<p[i]<<"  "<<"|";
	}
	cout<<"\n___________________________________________________";
	cout<<"\n"<<"0";
	for(int i=0;i<n;i++)
    {
    	cout<<"      "<<tat[i];
	}
	cout<<"\navg waiting time is   "<<a1<<"ms\n";
	cout<<"avg  turnarround time is   "<<a2<<"ms";
}
