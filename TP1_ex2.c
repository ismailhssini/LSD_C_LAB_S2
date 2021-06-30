#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};
typedef struct node node;
typedef node* t_list;

t_list create_node(int);         //Creating a node
void add_node(t_list,int value); //Adding a node to an existing one
t_list array_to_list(int* ,int); //Creating a list based on the array values
void print_list(t_list);         //Printing the list values
void remove_node(t_list*,int);  //Removing a node from the overall list
void free_node(t_list);          //Freeing the allocated nodes in the overall list
t_list create_list(int n);       //(Not required from the exercice) Creating an overall list 

t_list create_node(int value){
    t_list c=(t_list)malloc(sizeof(node));
    c->value=value;
    c->next=NULL;
    return c;
}

void add_node(t_list L,int value){
    t_list n=create_node(value);
    t_list p=L;
    if(p==NULL){
        L=n;
    }
    else{
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=n;
    }
    return;
}

t_list create_list(int n){
    t_list L;
    int value;
    printf("Please enter the values: ");
    scanf("%d",&value);
    L=create_node(value);
    for(int i=1;i<n;i++){
        scanf("%d",&value);
        add_node(L,value);
    }
    return L;
}

t_list array_to_list(int* T,int size){
    t_list L;
    if(size==0)
        return L;
    L=create_node(T[0]);
    for (int i = 1; i < size ; i++)
    {
        add_node(L,T[i]);
    }
    return L;
}

void print_list(t_list L){
    t_list p=L;
    if(p==NULL)
        printf("[ ]\n");
    else{
        printf("[ ");
        while (p->next!=NULL)
        {
            printf("%d , ",p->value);
            p=p->next;
        }
        printf("%d ]\n",p->value);
    }
    return ;
}

void remove_node(t_list * L,int n){
    t_list p=*L,t=*L;
    int i=0,j=0;
    if(p==NULL){
        printf("There is nothing to remove.\n");
        return ;
    }
    while (p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    p=*L;
    if(n<=i && n>0){
        while (j<n)
        {
            p=t;
            t=t->next;
            j++;
        }
        p->next=t->next;
        free(t);
        return ;
    }
    else{
        if(n==0){
            *L=(*L)->next;
            free(t);
            return ;
        }
        else{
            printf("The adress you have chosen is outside the range of the list and nothing changes.\n");
            return ;
        }
    }
}

void free_node(t_list L){
    while(L!=NULL){
        t_list p=L;
        L=L->next;
        free(p);
    }
    return ;
}

int main(){
    t_list c;
    t_list* k=&c;
    int n,T[n],m;
    printf("Enter the desired array length: ");
    scanf("%d",&n);
    if(n>0){
        printf("Please start typing the array values:\n");
        for(int i=0;i<n;i++){
            scanf("%d",&T[i]);
        }
        c=array_to_list(T,n);
        print_list(c);
        printf("Remove a node by typing it int address: ");
        scanf("%d",&m);
        remove_node(k,m);
    }
    else{
        c=array_to_list(T,n);
    }
    print_list(c);
    free_node(c);
    return 0;
}



