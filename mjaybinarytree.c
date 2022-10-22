#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct bst
 {
 	int data;
 	struct bst *left;
 	struct bst *right;
 };
 
 struct bst * insert(struct bst *,int);
 void inorder(struct bst *);
 void preorder(struct bst *);
 void postorder(struct bst *);
 
 int main ()
  {
  	struct bst *r=NULL;
  	  r=insert(r,30);
  	  r=insert(r,15);
  	  r=insert(r,10);
  	  r=insert(r,20);
  	  r=insert(r,40);
  	  r=insert(r,5);
  	  r=insert(r,45);
  	  r=insert(r,35);
  	  printf("\n display element in inorder:-");
  	  inorder(r);
  	  printf("\n display element in preorder:-");
  	  preorder(r);
  	  printf("\n display element in postorder:-");
  	  postorder(r);
  	 return 1;
  	 
   } 
   
   struct bst * insert(struct bst *q,int val)
    {
      struct bst *tmp;
      tmp=(struct bst *)malloc(sizeof(struct bst));
      
    	if(q==NULL)
    	 { 
    	 	 tmp->data=val;
    	 	 tmp->left=tmp->right=NULL;
    	 	 return tmp;
		 }
		 else
		  {
		  	 if(val<(tmp->data))
		  	   {
		  	   	  q->left=insert(q->left,val);
			   }
		  	 else
		  	  {
		  	  	 q->right=insert(q->right,val);
		      }
		  }
		 return q; 
	}
	
	
	 void inorder(struct bst *q)
	 {
	  	
	 	if(q==NULL)
	 	 {
	 	 	return;
	     }
	      
	 	   inorder(q->left);
	 	   printf(" %d ",q->data);
		   inorder(q->right);	
	 }
	
	
	void preorder(struct bst *q)
	 {
	  	
	 	if(q!=NULL)
	 	 {
		  printf(" %d ",q->data);
		  preorder(q->left);
		  preorder(q->right);
	     }
	     
	 }
	 
	 void postorder(struct bst *q)
	 {
	  	
	 	if(q!=NULL)
	 	 {
	 	   postorder(q->left);
		   postorder(q->right);	
		   printf(" %d ",q->data);
		  
		  
	     }
	     
	 }
	 
Output
	
 display element in inorder:- 35  45  5  40  20  10  15  30
 display element in preorder:- 30  15  10  20  40  5  45  35
 display element in postorder:- 35  45  5  40  20  10  15  30
--------------------------------
