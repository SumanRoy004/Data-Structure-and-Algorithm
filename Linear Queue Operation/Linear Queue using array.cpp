#include <iostream>
#define max 100
using namespace std;
int a[max],front=-1,rear=-1;
void enqueue(int [],int,int*,int*,int);
int dequeue(int [],int*,int*,int);
int main()
{ int ch,x,y;
while(1)
{cout<<"1.Enque\n2.Deque\nEnter your choice which you want to perform:";
cin>>ch;
switch(ch)
{ case 1:
	cout<<"Enter the value which you want to insert:";
	cin>>x;
	enqueue(a,x,&front,&rear,max);
	break;
  case 2:
  	y=dequeue(a,&front,&rear,max);
  	if(y)
      cout<<"Deleted element is:"<<y<<endl;
    
  	break;
  default:
  	cout<<"Enter the correct key.\n";
}
}
return 0;
}
void enqueue(int a[],int x,int* FRONT,int* REAR,int size)
{ if(*REAR==size-1)
  { cout<<"Queue is overflow"<<endl;
  }
  else
  { if(*FRONT==-1)
        *FRONT=0;
  *REAR=*REAR+1;
  a[*REAR]=x;
  }
}
int dequeue(int a[],int* FRONT,int* REAR,int size)
{ if(*FRONT==-1 && *REAR==-1)
{ cout<<"Queue is underflow"<<endl;
return 0;
}
else
{ int x=a[*FRONT];
if(*FRONT==*REAR)
{ *FRONT=-1;
  *REAR=-1;
}
else
{ *FRONT=*FRONT+1;
}
return x;
}
}
