#include <iostream>
#include <cstdlib>
using namespace std;
void merge(int*,int*,int,int);
int noc_1=0,noc_2=0;
void mergesort(int* a,int l,int r)
{ if(l<r)
 { int mid=(l+r)/2;
   mergesort(a,l,mid);
   mergesort(a,mid+1,r);
   merge(a+l,a+mid+1,mid-l+1,r-mid);
 }
}
void merge(int* c,int* d,int m,int n)
{ int* e=(int*)malloc((m+n)*sizeof(int));
int i=0,j=0,k=0;
while(i<m && j<n)
{ if(c[i]<d[j])
  { e[k++]=c[i++];
  noc_1=noc_1+1;
  }
  else
  { e[k++]=d[j++];
  noc_1=noc_1+1;
  }
  
}
for(;i<m;i++)
{    e[k++]=c[i];
noc_1=noc_1+1;
}
for(;j<n;j++)
{    e[k++]=d[j];
noc_1=noc_1+1;
}
for(i=0;i<m;i++)
{ noc_1=noc_1+1;
c[i]=e[i];
}
j=m;
for(i=0;i<n;i++)
{noc_1=noc_1+1; 
d[i]=e[j++];
}
}
void quicksort(int* a,int l,int r)
{ if(r>l)
  { int pivot=a[l],i=l,j=r;
  while(i<j)
  { while(a[i]<=pivot && i<=r-1)
    { i++;
    noc_2=noc_2+1;
	}
	while(a[j]>pivot && j>=l+1)
	{ j--;
	noc_2=noc_2+1;
	}
	if(i<j)
	{ int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	noc_2=noc_2+1;
	}
  }
  int temp=a[j];
  a[j]=a[l];
  a[l]=temp;
  quicksort(a,r,j-1);
  quicksort(a,j+1,l);
  }
}
int main()
{ int n,i,j,*a,*b,*c;
cout<<"Enter the size of array:";
cin>>n;
a=(int*)malloc(n*sizeof(int));
b=(int*)malloc(n*sizeof(int));
c=(int*)malloc(n*sizeof(int));
for(i=0;i<100;i++)
{ for(j=0;j<n;j++)
  { a[j]=rand()%n;
  }
  for(j=0;j<n;j++)
  { b[j]=a[j];
    c[j]=a[j];
  } 
  mergesort(b,0,n-1);
  quicksort(c,0,n-1);
}
cout<<"Avg No of Comparison of merge sort:"<<noc_1/100.0<<endl;
cout<<"Avg No of Comparison of quick sort:"<<noc_2/100.0<<endl;
return 0;
}

