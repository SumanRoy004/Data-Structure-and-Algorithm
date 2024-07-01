#include <stdio.h>
#include <stdlib.h>
typedef struct node
{ int data;
struct node* link;
}node;
node* root=NULL;
void addatbegin(node**,int);
void append(node**,int);
void addatkthpos(node**,int,int);
void delatbegin(node**);
void delatend(node**);
void delatkthpos(node**,int);
void diskthpos(node**,int);
void changekthpos(node**,int,int);
int len(node**);
int main()
{while(1)
{int ch,val_1,val_2,val_3,k_1,k_4,k_2,k_3,val_4;
printf("\nEnter your choice which you want:\n1.Insert at begining\n2.Insert at end\n3.Insert at kth pos\n4.Delete from begining\n5.Delete from end\n6.Delete from kth pos\n7.Display the content of kth pos\n8.Changing the content of kth pos\nNow,enter any number between 1 to 8:");
scanf("%d",&ch);
switch(ch)
{ case 1:
	printf("\nEnter the element:");
	scanf("%d",&val_1);
	addatbegin(&root,val_1);
	break;
  case 2:
  	printf("\nEnter the element:");
  	scanf("%d",&val_2);
  	append(&root,val_2);
  	break;
  case 3:
  	printf("\nEnter the element:");
  	scanf("%d",&val_3);
  	printf("\nEnter the pos:");
  	scanf("%d",&k_1);
  	addatkthpos(&root,val_3,k_1);
  	break;
  case 4:
  	delatbegin(&root);
  	break;
  case 5:
  	delatend(&root);
  	break;
  case 6:
  	printf("\nEnter the pos:");
  	scanf("%d",&k_4);
  	delatkthpos(&root,k_4);
  	break;
  case 7:
  	printf("\nEnter the pos:");
  	scanf("%d",&k_2);
  	diskthpos(&root,k_2);
  	break;
  case 8:
  	printf("\nEnter the pos:");
  	scanf("%d",&k_3);
  	printf("\nEnter the element:");
  	scanf("%d",&val_4);
  	changekthpos(&root,val_4,k_3);
  	break;
  default:
  	printf("Wrong Choice\n");
}
}
return 0;
}
void addatbegin(node** head,int x)
{node* temp=(node*)malloc(sizeof(node));
if(temp==NULL)
    printf("Memory not allocated\n");
else
{ temp->data=x;
  temp->link=NULL;
  if(*head==NULL)
  { *head=temp;
  }
  else
  { temp->link=*head;
    *head=temp;
  }
}
temp=NULL;
head=NULL;
}
void append(node** head,int x)
{ node* temp=(node*)malloc(sizeof(node));
if(temp==NULL)
   printf("Memory not allocated\n");
else
{temp->data=x;
  temp->link=NULL;
  if(*head==NULL)
  { *head=temp;
  }
  else
  { node* p=*head;
  if(p->link==NULL)
       p->link=temp;
  else
  {while(p->link!=NULL)
       p=p->link;
  p->link=temp;
  }
  p=NULL;
  }
}
temp=NULL;
head=NULL;
}
void addatkthpos(node** head,int x,int k)
{node* temp=(node*)malloc(sizeof(node));
if(temp==NULL)
    printf("Memory not allocated\n");
else
{if(k>=1 && k<=len(head))
{temp->data=x;
temp->link=NULL;
node* p=*head;
 for(int i=1;i<k-1;i++)
  { p=p->link;
  }
  temp->link=p->link;
  p->link=temp;
  p=NULL;
}
else
   printf("Wrong pos.\n");
}
temp=NULL;
head=NULL;
}
void delatbegin(node** head)
{ if(*head==NULL)
  { printf("List is empty.\n");
  }
  else
  { node* p=*head;
  if(p->link==NULL)
      free(p);
  else
  {*head=p->link;
  free(p);
  }
  p=NULL;
  }
  head=NULL;
}
void delatend(node** head)
{ if(*head==NULL)
   { printf("List is empty.\n");
   }
   else
   {node* p=*head;
   if(p->link==NULL)
         free(p);
    else
    { while(p->link->link!=NULL)
           p=p->link;
      free(p->link);
      p->link=NULL;
	}
	p=NULL;
   }
   head=NULL;
}
void delatkthpos(node** head,int k)
{ if(k>=1 && k<=len(head))
  { node* p=*head;
    for(int i=1;i<k-1;i++)
        p=p->link;
    node* q=p->link;
    p->link=q->link;
    free(q);
    p=NULL;
    q=NULL;
   }
   else
   { printf("Wrong pos.\n");
   }
head=NULL;
}
void diskthpos(node** head,int k)
{if(k<=len(head) && k>=1)
 { node* p=*head;
   for(int i=1;i<k;i++)
       p=p->link;
   printf("%d",p->data);
   p=NULL;
 }
 else
 { printf("Wrong pos.\n");
 }
 head=NULL; 
}
void changekthpos(node** head,int x,int k)
{ if(k>=1 && k<=len(head))
   { node* p=*head;
   for(int i=1;i<k;i++)
        p=p->link;
    p->data=x;
    p=NULL;
   }
   else
      printf("Wrong pos.\n");
   head=NULL;
}
int len(node** head)
{ int count=0;
node* p=*head;
while(p!=NULL)
{ p=p->link;
   count++;
}
head=NULL;
p=NULL;
return (count);
}
