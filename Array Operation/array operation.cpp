#include <stdio.h>
#define max 100
void addatbegin(int [],int*,int,int);
void append(int [],int*,int,int);
void addatkthpos(int [],int*,int,int,int);
void delatbegin(int [],int*);
void delatend(int [],int*);
void delatkthpos(int [],int*,int);
void diskthpos(int [],int*,int);
void changekthpos(int [],int*,int,int);
int m[max],n=0;
int main(void)
{ while(1)
{int ch,val_1,val_2,val_3,k_1,k_2,k_3,k_4,val_4;
printf("\nEnter your choice which you want:\n1.Insert at begining\n2.Insert at end\n3.Insert at kth pos\n4.Delete from begining\n5.Delete from end\n6.Delete from kth pos\n7.Display the content of kth pos\n8.Changing the content of kth pos\nNow,enter any number between 1 to 8:");
scanf("%d",&ch);
switch(ch)
{ case 1:
	printf("\nEnter the element:");
	scanf("%d",&val_1);
	addatbegin(m,&n,val_1,max);
	break;
  case 2:
	printf("\nEnter the element:");
	scanf("%d",&val_2);
  	append(m,&n,val_2,max);
  	break;
  case 3:
  	printf("\nEnter the element:");
  	scanf("%d",&val_3);
  	printf("\nEnter the pos:");
  	scanf("%d",&k_1);
  	addatkthpos(m,&n,val_3,k_1,max);
  	break;
  case 4:
  	delatbegin(m,&n);
  	break;
  case 5:
  	delatend(m,&n);
  	break;
  case 6:
  	printf("\nEnter the pos:");
  	scanf("%d",&k_2);
  	delatkthpos(m,&n,k_2);
  	break;
  case 7:
  	printf("\nEnter the pos:");
  	scanf("%d",&k_3);
  	diskthpos(m,&n,k_3);
  	break;
  case 8:
  	printf("\nEnter the pos:");
  	scanf("%d",&k_4);
  	printf("\nEnter the changing value:");
  	scanf("%d",&val_4);
  	changekthpos(m,&n,k_4,val_4);
  	break;
  default:
  	printf("Wrong Choice\n");
}
}
return 0;
}
void addatbegin(int a[],int* p,int x,int size)
{if(*p==size)
    printf("Overflow condition.\n");
else
{ int i;
for(i=*p-1;i>=0;i--)
   {a[i+1]=a[i];
   }
   a[i+1]=x;
*p=*p+1;
}
}
void append(int a[],int* p,int x,int size)
{if(*p==size)
  printf("overflow condition.\n");
else
{  a[*p]=x;
*p=*p+1;
}
}
void addatkthpos(int a[],int* p,int x,int k,int size)
{if(*p==size)
   printf("Overflow condition.\n");
else
{ if(k<=*p && k>=1)
  { int i;
  for(i=*p-1;i>=k-1;i--)
       a[i+1]=a[i];
    a[i+1]=x;
    *p=*p+1;
  }
  else
    printf("Wrong pos.\n");
}
}
void delatbegin(int a[],int* p)
{if(*p==0)
    printf("Underflow condition.\n");
 else
 { for(int i=1;i<*p;i++)
        a[i-1]=a[i];
*p=*p-1;
 }
}
void delatend(int a[],int* p)
{ if(*p==0)
      printf("Underflow condition.\n");
else
{ *p=*p-1;
}
}
void delatkthpos(int a[],int* p,int k)
{if(*p==0)
  printf("Underflow condition.\n");
else
{ if(k<=*p &&k>=1)
  { for(int i=k-1;i<*p-1;i++)
         a[i]=a[i+1];
    *p=*p-1;
  }
  else
    printf("Wrong pos.\n");
}
}
void diskthpos(int a[],int* p,int k)
{if(*p==0)
   printf("Underflow condition.\n");
else
{ if(k<=*p && k>=1)
      printf("%d",a[k-1]);
  else
     printf("Wrong pos.\n");
 }
}
void changekthpos(int a[],int* p,int k,int x)
{ if(k<=*p && k>=1)
{a[k-1]=x;
}
else
   printf("Wrong pos.\n");
}
