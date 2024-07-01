#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct node
{ struct node* lc;
int data;
struct node* rc;
} node;
node* head=NULL;
node* newnode(int);
node* insertion(node*,int);
int height(node*);
int max(int,int);
int fun(int*,int);
int main()
{ int i,j,a[1000],n;
float mean=0.0;
cout<<"Enter the no of random number:";
cin>>n;
for(i=1;i<=1000;i++)
{ for(j=1;j<=n;j++)
  { head=insertion(head,(rand()%n)); 
  }
  a[i-1]=height(head);
}
sort(a,a+1000);
for(i=0;i<1000;i++)
{ if(fun(a,i))
  { cout<<a[i]<<" "<<count(a,a+1000,a[i])<<endl;
  }
}
for(i=0;i<1000;i++)
{ mean=mean+a[i];
}
mean=(float)mean/1000;
cout<<"mean="<<mean;
return 0; 
}
node* newnode(int x)
{ node* temp=(node*)malloc(sizeof(node));
temp->data=x;
temp->lc=NULL;
temp->rc=NULL;
return (temp);
}
node* insertion(node* root,int x)
{ if(root==NULL)
       return newnode(x);
  if(x<root->data)
       root->lc=insertion(root->lc,x);
    else
    { if(x>root->data)
          root->rc=insertion(root->rc,x);
    }
  return (root);
}
int max(int a,int b)
{ if(a>b)
      return a;
  else
     return b;
}
int height(node* root)
{ if(root==NULL)
  {return (-1);
  }
  else
    return (1+max(height(root->lc),height(root->rc)));
}
int fun(int* p,int i)
{ int j;
for(j=i-1;j>=0;j--)
{ if(p[i]==p[j])
  { return 0;
  }
}
return 1;
}
