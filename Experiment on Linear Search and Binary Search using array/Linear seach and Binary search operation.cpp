#include <iostream>
#include <cstdlib>
using namespace std;
int linear_search(int*,int,int);
int binary_search(int*,int,int);
int bubble_sort(int*,int);
int main()
{ int *p,n,m,max,min,count1=0,count2=0,count3,i;
cout<<"Enter the size of array(value of n):"<<endl;
cin>>n;
cout<<"Enter the number of search(value of m):"<<endl;
cin>>m;
cout<<"Enter the range which you want to insert and also search(first min and second max):"<<endl;
cin>>min>>max;
p=new int[n];
for(i=0;i<n;i++)
{ p[i]=(rand()%(max-min+1))+min;
}
for(i=0;i<m;i++)
{int linear_value=(rand()%(max-min+1))+min;
count1=count1+linear_search(p,n,linear_value);
}
cout<<"Number of comparison of linear search:"<<count1<<endl;
count3=bubble_sort(p,n);
for(i=0;i<m;i++)
{  int binary_value=(rand()%(max-min+1))+min;
count2=count2+binary_search(p,n,binary_value);
}
cout<<"Number of comparison of binary search:"<<count2+count3<<endl;

return 0;

}
int linear_search(int* p,int size,int x)
{int i,count=0;
for(i=0;i<size;i++)
{ count++;
if(x==p[i])
{ break;
}
}
return (count);
}
int binary_search(int* p,int size,int x)
{ int l=0,r=size-1,mid,count=0;
while(r>=l)
{ mid=(r+l)/2;
count++;
if(x==p[mid])
    break;
if(x<p[mid])
    r=mid-1;
if(x>p[mid])
    l=mid+1;
}
return (count);
}
int bubble_sort(int* p,int size)
{ int i,j,count=0;
for(i=0;i<size-1;i++)
{ for(j=0;j<size-i-1;j++)
  { count++;
  if(p[j]>p[j+1])
    { int temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
	}
  }
}
return (count);
}
