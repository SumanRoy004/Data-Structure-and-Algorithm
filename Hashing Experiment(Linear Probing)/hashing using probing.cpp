#include <iostream>
#include <cstdlib>
using namespace std;
void insertion(int*,int,int);
int search(int*,int,int);
int main()
{ int max,min,n,m,*a,k,i,cmpno=0;
cout<<"Enter the range(min and max order) which you want to insert in hash table:";
cin>> min >> max;
cout<<"Enter the value of number of elements to be inserted(n(<m)):";
cin>>n;
cout<<"Enter the size of hash table(m):";
cin>>m;
a=(int*)calloc(m,sizeof(int));
for(i=1;i<=n;i++)
{ k=(rand()%(max-min+1))+min;
insertion(a,k,m);
}
for(i=1;i<=1000;i++)
{ k=(rand()%(max-min+1))+min;
cmpno=cmpno+search(a,k,m);
}
cout<<cmpno/(float)1000;
return 0;
}
void insertion(int* p,int val,int size)
{ int i=val%size;
while(p[i%size]!=0)
{ i++;
}
p[i%size]=val;
}
int search(int* p,int val,int size)
{ int i=val%size,count=1;
while(p[i%size]!=val)
{ count++;
if(p[i%size]==0)
{  count--;
break;
}
i++;
if(i%size==(val%size))
{ count--;
break;
}
}
return (count);
}
