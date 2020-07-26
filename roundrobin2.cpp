#include<iostream>
using namespace std;
int main()
{
	int a[10],b[10],ta[10],w[10],bt[10],i,n,q,s1=0,s2=0,x,t=0,c=1,k=0,l[30],j=1;
	string p[10];
	float a1,a2;
	cout<<"Enter no. of processes:";
    cin>>n;
	cout<<"Enter Quantum time:";
    cin>>q;
    l[0]=0;
	for(i=0;i<n;i++)
    {
    	cout<<"Enter process id["<<i+1<<"]:";
    	cin>>p[i];
    	cout<<"Enter burst time["<<i+1<<"]:";
    	cin>>b[i];
    	bt[i]=b[i];
    	k=k+b[i];
	}
	for(i=0;i<k;i++)
	cout<<"__";
	cout<<"\n";
	while(c)
	{
		x=1;
		for(i=0;i<n;i++)
		{
			if(bt[i]>0)
			{
				x=0;
				if(bt[i]>q)
				{
					t=t+q;
					bt[i]=bt[i]-q;
					cout<<"|  "<<p[i]<<"  |";
					l[j]=t;
					j++;
				}
				else
				{
					t=t+bt[i];
					w[i]=t-b[i];
					bt[i]=0;
					cout<<"|  "<<p[i]<<"  |";
					l[j]=t;
					j++;
				}
			}
		}
		if(x==1)
		c=0;
	}
	cout<<"\n";
	for(i=0;i<k;i++)
	cout<<"__";
	cout<<"\n";
	for(i=0;i<j;i++)
	cout<<l[i]<<"     ";
	for(i=0;i<n;i++)
	ta[i]=b[i]+w[i];
	for(i=0;i<n;i++)
	{
		s1=s1+w[i];
		s2=s2+ta[i];
	}
	a1=(float)s1/n;
	a2=(float)s2/n;
	cout<<"\nProcesses name\tBurst time\tComplition time\tWaiting time\tTurn around time\n";
	for(i=0;i<n;i++)
	cout<<p[i]<<"\t  \t"<<b[i]<<"\t  \t"<<ta[i]<<"\t  \t"<<w[i]<<"\t  \t"<<ta[i]<<"\n";
	cout<<"Average Waiting time:"<<a1<<"ms\n";
	cout<<"Average Turnaround time:"<<a2<<"ms\n";
	return 0;
}
