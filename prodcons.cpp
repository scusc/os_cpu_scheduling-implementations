#include<iostream>
using namespace std;
int main()
{
	int in,out,buffer[10],bufsize,prod,cons;
	int choice=0;
	in=0;
	out=0;
	bufsize=10;
	while(choice!=3)
	{
		cout<<"\n 1.produce 2.consume 3.exit";
		cout<<"\nenter choice";
		cin>>choice;
		switch(choice)
		{
			case 1:if((in+1)%bufsize==out)
			{
				cout<<"buffer is full";
			}
			else
			{
				cout<<"enter item";
				cin>>prod;
				buffer[in]=prod;
				in=(in+1)%bufsize;
			}
			break;
			case 2:if(in==out)
			{
				cout<<"buffer is empty";
			}
			else
			{
				cons=buffer[out];
				cout<<"\n consumer value is"<<cons;
				out=(out+1)%bufsize;
	 	    }
			 break;  
		}
	}
}
