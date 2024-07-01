#include <iostream>
#include <unordered_map>
using namespace std;
int noc=0;
typedef struct node
{ int data;
int rank;
node* parent;
}node;
unordered_map<int,node*> val;
node* makeset(int x)
{ node* temp=(node*)malloc(sizeof(node));
temp->data=x;
temp->rank=1;
temp->parent=temp;
return (temp);
}
int find(int x)                        /*Here I forgot to change the rank of the main parent after path compression,that's why it gives wrong result.*/
{  if(val[x]==val[x]->parent)
   {  return (val[x]->parent->data);
   }
   val[x]->parent=val[find(val[x]->parent->data)];
   noc++;
   return (val[x]->parent->data);
}
void Union(int x,int y)
{if(find(x)!=find(y))
{if(val[find(x)]->rank>val[find(y)]->rank)
   {     val[find(y)]->parent=val[find(x)];
   }
  else
    if(val[find(x)]->rank<val[find(y)]->rank)
    {       val[find(x)]->parent=val[find(y)];
	}
	else
	{  val[find(y)]->parent=val[find(x)];
	   val[find(x)]->rank=val[find(x)]->rank+1;  
    }
}
}
int main()
{ int n,m,x,y,z,flag;
cout<<"Enter the value of n:";
cin>>n;
for(int i=1;i<=n;i++)
{val[i]=makeset(i);
noc++;
} 
cout<<"Enter the value of m:";
cin>>m;
for(int i=1;i<=m-n;i++)
{ flag=rand()%2;
if(flag==0)
{ z=1+(rand()%100);
find(z);
}
if(flag==1)
{ noc++;
x=1+(rand()%100);
y=1+(rand()%100);
Union(x,y);
}
}
cout<<noc; 
return 0;
}
