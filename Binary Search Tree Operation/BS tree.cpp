#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{ struct node* lc;
int data;
struct node* rc;
} node;
node* head=NULL;
node* newnode(int);
node* insertion(node*,int);
node* deletion(node*,int);
void inorder(node*);
node* predecessor(node*);
int height(node*);
int max(int,int);
int main()
{ int n,i,x,k;
cout<<"Enter the no of values:";
cin>>n;
for(i=1;i<=n;i++)
{ cout<<"Enter "<<i<<"th value:";
cin>>x;
head=insertion(head,x);
}
inorder(head);
cout<<height(head)<<endl;
cout<<"Enter the value you wanna delete:";
cin>>k;
head=deletion(head,k);
inorder(head);
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
       if(x>root->data)
            root->rc=insertion(root->rc,x);
  return (root);
}
void inorder(node* root)
{ if(root!=NULL)
   { inorder(root->lc);
     cout<<root->data<<" ";
     inorder(root->rc);
   }
}
node* predecessor(node* root)
{ node* temp=root->lc;
while(temp->rc!=NULL)
{ temp=temp->rc;
}
return (temp);
}
node* deletion(node* root,int x)
{ if(root==NULL)
      return (root);
  if(x<root->data)
    root->lc=deletion(root->lc,x);
  else
  { if(x>root->data)
       root->rc=deletion(root->rc,x);
    else
	{ if(root->lc==NULL)
	  {    node* temp=root->rc;
		   free(root);
		   return (temp);
      }
      else
	   { if(root->rc==NULL)
		  {  node* temp=root->lc;
		     free(root);
		     return (temp);
		  }
		   node* temp=predecessor(root);
		   root->data=temp->data;
		   root->lc=deletion(root->lc,temp->data);
		  
	    }
	}
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
