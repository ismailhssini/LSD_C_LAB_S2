

#include <stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node * left;
    struct node * right;
};
typedef struct node node;
typedef struct node * tree;

// Prototypes
tree MakeTree(int, tree,tree); 
void FreeTree(tree *T); 

// Implementations

// faireArbre
tree MakeTree(int x,tree T_1,tree T_2)
{
    tree T=(tree)malloc(sizeof(node));
    T->key=x;
    T->left=T_1;
    T->right=T_2;
    return T;
}



// Liberer
void FreeTree(tree *T)
{
    tree temp=*T;
    if(temp==NULL)
        return;
    if(temp->left!=NULL)
        FreeTree(&temp->left);
    if(temp->right!=NULL)
        FreeTree(&temp->right);
    free(temp);
    *T=NULL;
}

int max(int x,int y)
{
	if (x>y)
		return x;
	return y;
}

int DepthTree(tree T)
{
	if (T==NULL)
		return 0;
	if (T->left!=NULL || T->right!=NULL)
		return 1+max(DepthTree(T->left),DepthTree(T->right));
}

int diameterTree(tree T)
{
	if (T==NULL)
		return 0;
	int lDepthTree= DepthTree(T->left);
    int rDepthTree = DepthTree(T->right);
    int ldiameter = diameterTree(T->left);
    int rdiameter = diameterTree(T->right);
    return max(lDepthTree + rDepthTree + 1,max(ldiameter, rdiameter));
}
int leaf_sum(tree T)
{
	if (T==NULL)
		return 0;
	if (T->left==NULL && T->right==NULL)
		return T->key;
	return leaf_sum(T->left)+leaf_sum(T->right);
}

int SearchBst(tree T,int x)
{
	if (T==NULL)
		return 0;
	if (T->key==x)
		return 1;
	if (SearchBst(T->left,x)==0 && SearchBst(T->right,x)==0)
		return 0;
	return 1;
}

void insertTree(tree T,int x)
{
	if (T==NULL)
		T=MakeTree(x,NULL,NULL);
		return;
	if (T->key==x)
		return ;
	tree temp=T,temp1=T;
	while (temp!=NULL)
		if (x==temp->key)
			return;
		if (x<temp->key)
			temp=temp->left;
		temp=temp->right;
	if (temp1->key==x)
		return;
	tree B=MakeTree(x,NULL,NULL);
	if (temp1->key<x)
		T=MakeTree(temp1->key,B,NULL);
		return;
	return MakeTree(temp1->key,NULL,B);
}

int Tree_size(tree T)
{
	if (T==NULL)
		return 0;
	return 1+Tree_size(T->left)+Tree_size(T->right);
}



int main()
{
	int a,b,c;
    tree T1=NULL;
    tree T2=NULL;
    tree T3=NULL;
    tree T4=NULL;
    T1=MakeTree(1,NULL,NULL);
    T2=MakeTree(88,NULL,NULL);
    T3=MakeTree(-77,NULL,NULL);
    T4=MakeTree(-1,NULL,NULL);
    tree T=MakeTree(3,T1,T2);
    tree S=MakeTree(9,T3,T4);
    tree W=MakeTree(6,T,S);
    a=DepthTree(W);
    b=leaf_sum(W);
    c=diameterTree(W);
    int d=SearchBst(W,28);
    printf("the depth of the tree W is %d \n\n",a);
    printf("the sum of leaves value of this tree is %d \n\n",b);
    printf("the diameter og the tree W is %d \n\n",c);
    printf("%d",d);
    FreeTree(&W);
    return 0;
}
