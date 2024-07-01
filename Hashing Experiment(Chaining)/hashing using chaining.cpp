#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{ int data;
struct node* link;
} node;
void addatbegin(node**,int);
int search(node**,int,int);
int main()
{ int max,min,n,i,k,entry,cmpno=0,m;
node** a;
cout<<"Enter the range(min and max order) which you want to insert in hash table:";
cin>> min >> max;
cout<<"Enter the value of number of elements to be inserted(n):";
cin>>n;
cout<<"Enter the size of hash table(m):";
cin>>m;
a=(node**)calloc(m,sizeof(node*));
for(i=1;i<=n;i++)
{ k=(rand()%(max-min+1))+min;
addatbegin(&a[k%m],k);
}
for(i=1;i<=1000;i++)
{ entry=(rand()%(max-min+1))+min;
cmpno=cmpno+search(a,entry,m);
}
cout<<cmpno/(float)1000;
return 0;
}
void addatbegin(node** head,int x)
{ node* temp=(node*)malloc(sizeof(struct node));
if(temp==NULL)
     cout<<"Memory not allocated"<<endl;
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
int search(node** q,int val,int m)
{ node* p=q[val%m];
int count=0;
while(p!=NULL)
{    count++;
 if(p->data==val)
       break;
  p=p->link; 
}
return (count);
}
