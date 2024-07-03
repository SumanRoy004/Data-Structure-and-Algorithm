#include <iostream>
#include <unordered_map>
using namespace std;
int noc=0;
typedef struct node
{ int data;
int subset_size;
node* parent;
}node;
unordered_map<int,node*> val;
node* makeset(int x)
{ node* temp=(node*)malloc(sizeof(node));
temp->data=x;
temp->subset_size=1;
temp->parent=temp;
return (temp);
}
int find(int x)                    
{  if(val[x]==val[x]->parent)
   {  return (val[x]->parent->data);
   }
   val[x]->parent=val[find(val[x]->parent->data)];
   noc++;
   return (val[x]->parent->data);
}
void Union(int x,int y)
{ int px=find(x);
  int py=find(y);
if(px!=py)
 {if((val[px]->subset_size)>=(val[py]->subset_size))
    {    val[py]->parent=val[px];
         (val[px]->subset_size)+=(val[py]->subset_size);  
    }
  else
    if((val[px]->subset_size)<(val[py]->subset_size))
    {       val[px]->parent=val[py];
           (val[py]->subset_size)+=(val[px]->subset_size); 
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
