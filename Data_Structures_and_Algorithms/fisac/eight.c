#include<stdio.h>
#include<stdlib.h>

typedef struct emp{
int a;
struct emp *next;
}node;

node *head,*tail,*l1,*l2;

void input(node *p){
    scanf("%d",&(p->a));
    p->next=NULL;
}

void myadd(){
    node *t;
    t= (node*)calloc(1,sizeof(node));
    input(t);
    if(head==NULL)
        head = t;
    else
        tail->next=t;
    tail=t;
}

void mylist(){
    if(head==NULL){
        printf(" list is empty ");
        return;
    }
    node *t;
    for(t= head;t!=NULL;t=t->next)
        printf("%d ",t->a);
}


void main(){
    int ch;
    head= NULL;
    printf("Enter number of data to be added: ");
    scanf("%d",&ch);
    printf("Enter %d values: ",ch);
    for(int i=0;i<ch;i++)
        myadd();
    printf("The nodes are:\n");
    mylist();

    int i;
    node *t,*k1,*k2;
    l1=NULL;
    l2=NULL;
    for(i=1,t=head;t!=NULL;t=t->next,i++){
        if(i%2==1){
            if(l1==NULL){
                l1=t;
                k1=l1;
            }
            else{
                k1->next=t;
                k1=k1->next;
            }
        }
        else{
            if(l2==NULL){
                l2=t;
                k2=l2;
            }
            else{
                k2->next=t;
                k2=k2->next;
            }
        }
    }
    if(l1!=NULL)
        k1->next=NULL;
    if(l2!=NULL)
        k2->next=NULL;
    printf("\nLIST 1: ");
    for(t=l1;t!=NULL;t=t->next)
        printf("%d  ",t->a);
    printf("\nLIST 2: ");
    for(t=l2;t!=NULL;t=t->next)
        printf("%d  ",t->a);
    printf("\n");
}

