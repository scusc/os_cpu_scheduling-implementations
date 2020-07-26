#include<iostream>
using namespace std;
struct semaphore
{
	int mutex,rcount,rwait,wrt;
};
void addR(struct semaphore *s)
{
	if(s->mutex==0&&s->rcount==0)
	{
		cout<<"\n file is in write mode\nnew reader added to queue";
	}
	else
	{
		cout<<"\nreader procedure added";
		s->rcount++;
		s->mutex--;
	}
}
void addW(struct semaphore *s)
{
	if(s->mutex==1)
	{
		s->mutex--;
		s->wrt=1;
		cout<<"write procedure added";	
	}	
	else if(s->wrt)
	cout<<"\n file is read mode";
} 
void remR(struct semaphore *s)
{
	if(s->rcount==0)
	cout<<"\n no reader present";
	else
	{
	cout<<"\nreader removed";
	s->rcount--;
	s->mutex++;
    }
}
void remW(struct semaphore *s)
{
	if(s->wrt==0)
	cout<<"\n writer present";
	else
	{
	cout<<"write removed";
	s->mutex++;
	s->wrt=0;
	}
	if(s->wrt==0)
	{
		s->mutex-=s->rwait;
		s->rcount=s->rwait;
		s->rwait=0;
		cout<<"waiter reads added\n"<<s->rcount;
	}
}
int main()
{
	struct semaphore s1={1,0,0,0};
	int ch;
	while(ch!=5)
	{
		cout<<"\n 1.add reader  2.add writer  3.remove reader  4.remove writer  5.exit";
		cout<<"\nenter choice";
		cin>>ch;
		switch(ch)
		{
			case 1:addR(&s1);
			break;
			case 2:addW(&s1);
			break;
			case 3:remR(&s1);
			break;
			case 4:remW(&s1);
			break;
		}
		cout<<"\ncurrent status";
		cout<<"\nmutex :"<<s1.mutex<<"\nrcount :"<<s1.rcount<<"\nrwait :"<<s1.rwait<<"\nactive writer :"<<s1.wrt;
	}
}
