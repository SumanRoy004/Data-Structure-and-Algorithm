#include <iostream>
#include <cstdlib>
using namespace std;
int noc_1=0,nos_1=0,noc_2=0,nos_2=0,noc_3=0,nos_3=0;
void selectionsort(int* a,int size)
{ int i,j;
for(i=0;i<size-1;i++)
{ int k=i;
for(j=i+1;j<size;j++)
{ noc_1=noc_1+1;
if(a[i]>a[j])
  { k=j;
  }
}
if(k!=i)
{ int temp=a[i];
a[i]=a[k];
a[k]=a[i];
nos_1=nos_1+1;
}
}
}
void insertionsort(int* a,int size)
{ int i,j;
for(j=1;j<size;j++)
{ int key=a[j];
for(i=j-1;i>=0 && key<a[i];i--)
{ noc_2=noc_2+1;
a[i+1]=a[i];
}
a[i+1]=key;
}
}
void bubblesort(int* a,int size)
{int i,j;
for(i=0;i<size-1;i++)
{ int exchange=0;
for(j=0;j<size-i-1;j++)
{ noc_3=noc_3+1;
if(a[j]>a[j+1])
{ int temp=a[j];
   a[j]=a[j+1];
   a[j+1]=temp;
   exchange++;
   nos_3=nos_3+1;
}
}
if(exchange==0)
{ break;
}
}
}
int main()
{ int n,i,j,*a,*b,*c,*d;
cout<<"Enter the size of array:";
cin>>n;
a=(int*)malloc(n*sizeof(int));
b=(int*)malloc(n*sizeof(int));
c=(int*)malloc(n*sizeof(int));
d=(int*)malloc(n*sizeof(int));
for(i=0;i<100;i++)
{ for(j=0;j<n;j++)
  { a[j]=rand()%n;
  }
  for(j=0;j<n;j++)
  { b[j]=a[j];
    c[j]=a[j];
    d[j]=a[j];
  } 
  selectionsort(b,n);
  insertionsort(c,n);
  bubblesort(d,n);
}
cout<<"Avg No of Comparison of selection sort:"<<noc_1/100.0<<"\n"<<"Avg No of Swap of selection sort:"<<nos_1/100.0<<endl;
cout<<"Avg No of Comparison of insertion sort:"<<noc_2/100.0<<"\n"<<"Avg No of Swap of insertion sort:"<<nos_2/100.0<<endl;
cout<<"Avg No of Comparison of bubble sort:"<<noc_3/100.0<<"\n"<<"Avg No of Swap of bubble sort:"<<nos_3/100.0<<endl;
return 0;
}

