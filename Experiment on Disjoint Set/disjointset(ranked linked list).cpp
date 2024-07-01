#include <iostream>
#include <unordered_map>
using namespace std;
int noc=0;
typedef struct node
{ int data;
int rank;
node* next;
node* parent;
}node;
unordered_map<int,node*> val;
unordered_map<node*,node*> Set;
node* makeset(int x)
{ node* temp=(node*)malloc(sizeof(node));
temp->data=x;
temp->rank=1;
temp->next=NULL;
temp->parent=temp;
return (temp);
}
int find(int x)
{ noc++;
return (val[x]->parent->data);
}
void Union(int x,int y)
{if(find(x)!=find(y))
{if(val[x]->parent->rank<val[y]->parent->rank)
                    swap(x,y); 
val[x]->parent->rank=val[x]->parent->rank+val[y]->parent->rank;
Set[val[x]->parent]->next=val[y]->parent;
Set.erase(val[y]->parent);
node* temp=val[y]->parent;
while(temp->next!=NULL)
{temp->parent=val[x]->parent;
temp=temp->next;
noc++;
}
temp->parent=val[x]->parent;
Set[val[x]->parent]=temp;
}
}
int main()
{ int n,m,x,y,z,flag;
node* head;
node* tail;
cout<<"Enter the value of n:";
cin>>n;
for(int i=1;i<=n;i++)
{head=tail=makeset(i);
val[i]=head;
Set[head]=tail;
noc++;
} 
cout<<"Enter the value of m:";
cin>>m;
for(int i=1;i<=m-n;i++)
{flag=rand()%2;
if(flag==0)
{ z=1+(rand()%100);
find(z);
}
if(flag==1)
{x=1+(rand()%100);
y=1+(rand()%100);
Union(x,y);
}
}
cout<<noc; 
return 0;
}
