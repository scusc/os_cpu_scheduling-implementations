#include<iostream>
using namespace std;
int main()
{
	int n,a[10],b[10],c[10],rt[10],finish[10],w[10],ta[10],g[10];
	char p[10],v,z[10];
	int i,j=0,next,s1=0,s2=0,total=0,time,l,k;
	float a1,a2;
	cout<<"Enter no. of proceses:";
	cin>>n;
	for(i=0; i<n; i++) 
	{ 
		cout<<"Enter Process Id: "; 
		cin>>p[i]; 
		cout<<"Enter Arrival Time: "; 
		cin>>a[i]; 
		cout<<"Enter Burst Time: "; 
		cin>>b[i]; 
	} 
	for(i=0;i<n;i++)
	{
		rt[i]=b[i];
		finish[i]=w[i]=ta[i]=0;
		total+=b[i];
	}
	char s[total+10];
	for(time=0;time<total;time++)
	{
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
			l=i;
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]!=1)
		if(rt[i]<rt[l]&&a[i]<=time)
		{
		l=i;
	    }
	}
	next=l;
		rt[next]=rt[next]-1;
		if(rt[next]==0)
		finish[next]=1;
		for(i=0;i<n;i++)
		if(i!=next&&finish[i]==0&&a[i]<=time)
		w[i]++;
		s[j]=p[l];
		j++;
	}
	v=p[0];
	g[0]=a[0];
	for(i=0,j=1,k=0;i<total+1;i++)
	{
		if(s[i]!=v)
		{
			z[k]=v;
			g[j]=i;
			j++;
			k++;
			v=s[i];
		}
	}
	cout<<j<<"\n"<<k<<"\n";
	cout<<"_";
	for(i=0;i<j;i++)
	cout<<"____";
	cout<<"\n";
	for(i=0;i<k;i++)
	cout<<"| "<<z[i]<<" ";
	cout<<"|\n";
	cout<<"_";
	for(i=0;i<j;i++)
	cout<<"____";
	cout<<"\n";
	for(i=0;i<j;i++)
	cout<<g[i]<<"   ";	
    cout<<"\n"; 
	for(i=0;i<n;i++)
	{
		s1=s1+w[i];
		ta[i]=w[i]+b[i];
		s2=s2+ta[i];
		c[i]=ta[i]+a[i];
	}
	cout<<"Process ID\tArrival Time\tBurst Time\tCompletion time\tWaiting Time\tTurnaround Time\n"; 
	for(i=0;i<n;i++)
	{
	cout<<p[i]<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<c[i]<<"\t\t"<<w[i]<<"\t\t"<<ta[i]<<"\n";
	}
	a1=(float)s1/n;
	a2=(float)s2/n;
	cout<<"Average Waiting time="<<a1<<"ms\n";;
	cout<<"Average TurnAroundTime="<<a2<<"ms\n";;
	return 0;
}
