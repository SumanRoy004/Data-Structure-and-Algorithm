#include<iostream>
using namespace std;
#define max 100
int a[max],top=-1;
void push(int [],int,int*,int);
int pop(int [],int*,int);
int main()
{ int ch,x,y;
while(1)
{cout<<"1.Push\n2.Pop\nEnter your choice which you want to perform:";
cin>>ch;
switch(ch)
{ case 1:
	cout<<"Enter the value which you want to insert:";
	cin>>x;
	push(a,x,&top,max);
	break;
  case 2:
  	y=pop(a,&top,max);
  	if(y)
      cout<<"Deleted element is:"<<y<<endl;
    
  	break;
  default:
  	cout<<"Enter the correct key.\n";
}
}
return 0;
}
void push(int a[],int x,int* TOP,int size)
{ if(*TOP==size-1)
  { cout<<"Stack is Overflow"<<endl;
  }
  else
  { a[++(*TOP)]=x;
  }
}
int pop(int a[],int* TOP,int size)
{ if(*TOP==-1)
    {  cout<<"Stack is underflow"<<endl;
    return 0;
    }
  else
  { return (a[(*TOP)--]);
  }
}
