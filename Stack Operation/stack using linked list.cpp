#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{ int data;
struct node* link;
} node;
node* root=NULL;
void push(node**,int);
int pop(node**);
int main()
{int ch,x,y;
while(1)
{cout<<"1.Push\n2.Pop\nEnter your choice which you want to perform:";
cin>>ch;
switch(ch)
{ case 1:
	cout<<"Enter the value which you want to insert:";
	cin>>x;
	push(&root,x);
	break;
  case 2:
  	y=pop(&root);
  	if(y)
      cout<<"Deleted element is:"<<y<<endl;
    
  	break;
  default:
  	cout<<"Enter the correct key.\n";
}
}
return 0;
}
void push(node** head,int x)
{ node* temp=(node*)malloc(sizeof(node));
if(temp==NULL)
    cout<<"Stack is overflow"<<endl;
else
{ temp->data=x;
temp->link=NULL;
temp->link=*head;
*head=temp;
}
temp=NULL;
head=NULL;
}
int pop(node** head)
{ if(*head==NULL)
 {  cout<<"Stack is underflow"<<endl;
 head=NULL;
 return 0;
}
else
{node* p=*head;
*head=p->link;
int x=p->data;
free(p);
p=NULL;
head=NULL;
return x;
}
}

